#define REGISTER_LPN_CLASS(type, name, ...)                                                   \
template<class... Args>                                                                       \
Lpn##type####name* lpn_##type##_generator(Args... args)                                       \
{                                                                                             \
  return new Lpn##type####name(std::forward<Args>(args)...);                                  \
}                                                                                             \
Lpn##name##Factory lpn_##type##_##name##_factory(#type, lpn_##type##_generator<__VA_ARGS__>);

#define REGISTER_LPN_MODEL_CLASS(type) \
  REGISTER_LPN_CLASS(type, Model)

template<class T, class... Args>
class ClassFactory
{
#define class_genertaor std::function<T*(Args...)>

public:
  ClassFactory(const std::string&, class_genertaor);
  static T* generate_class(const std::string&, Args...);

private:
  static std::unordered_map<std::string, class_genertaor>& get_generators();
  static std::string get_class_names();
};

template<class T, class... Args>
ClassFactory<T, Args...>::ClassFactory(const std::string& class_name, class_genertaor generator)
{
  auto& generators = get_generators();
  generators[class_name] = generator;
}

template<class T, class... Args>
T* ClassFactory<T, Args...>::generate_class(const std::string& class_name, Args... args)
{
  auto& generators = get_generators();
  if (generators.find(class_name) == generators.end()){
    throw std::string("[Error] Cannot find class generator") + class_name + ", avail: " + get_class_names();
  }else{
    return generators[class_name](args...);
  }
}

template<class T, class... Args>
std::unordered_map<std::string, class_genertaor>& ClassFactory<T, Args...>::get_generators()
{
  static std::unordered_map<std::string, class_genertaor> generators;
  return generators;
}

template<class T, class... Args>
std::string ClassFactory<T, Args...>::get_class_names()
{
  std::string exist_classes_name("[");
  for(auto item : get_generators())
    exist_classes_name += (item.first + ",");
  exist_classes_name += "]";
  return exist_classes_name;
}
