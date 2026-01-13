#ifndef CORE_TEMPLATES_NODES_H_
#define CORE_TEMPLATES_NODES_H_

namespace core {

    // Singly Linked Node
    template <typename T>
    struct SL_Node {
        T value{};
        SL_Node* next{nullptr};  
    };

    // Doubly Linked Node
    template <typename T>
    struct DL_Node {
        T value{};
        DL_Node* next{nullptr};
        DL_Node* prev{nullptr};
    };

    // Singly Linked Key Value Node
    template <typename K, typename V>
    struct SL_KV_Node {
        K key{};
        V value{};
        SL_KV_Node* next{nullptr};
    };

    // Doubly Linked Key Value Node
    template <typename K, typename V>
    struct DL_KV_Node {
        K key{};
        V value{};
        DL_KV_Node* next{nullptr};
        DL_KV_Node* prev{nullptr};
    };

}

#endif // CORE_TEMPLATES_NODES_H_
