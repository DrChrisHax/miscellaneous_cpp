#ifndef CORE_TEMPLATES_TREE_H_
#define CORE_TEMPLATES_TREE_H_

namespace core {

template <typename T>
class Tree {
public:
    using value_type = T;
    virtual ~Tree() = default;
};

} // namespace core

#endif // CORE_TEMPLATES_TREE_H_