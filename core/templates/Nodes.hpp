#ifndef TEMPLATES_NODE_H_
#define TEMPLATE_NODE_H_

namespace core {

    template <typename T>
    struct Node {
        T value_;
        Node* next_{nullptr};
    };

    template <typename T>
    struct DLNode {
        T value_;
        DLNode* next_{nullptr};
        DLNode* prev_{nullptr};
    };

}


#endif // TEMPLATE_NODE_H_