#include "ObjectPool.h"

#include <memory>
#include <utility>

explicit ObjectPool::ObjectPool(std::size_t capacity){

}

ObjectPool::~ObjectPool() {

}

template <typename... Args>
Object* ObjectPool::TakeObject(Args&&... args) {

}

void ObjectPool::ReturnObject(Object* obj) {

}
