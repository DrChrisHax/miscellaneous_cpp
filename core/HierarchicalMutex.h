#ifndef CORE_HIERARCHICAL_MUTEXT_H_
#define CORE_HIERARCHICAL_MUTEXT_H_


#include <thread>

namespace core {

    class HierarchicalMutext {
    public:

        explicit HierarchicalMutext(uint64_t value) 
            : hierarchy_value_{value}
            , previous_hierarchy_value_{0}
        {}

        void Lock() {
            CheckForHierarchyViolation();
            internal_mutex_.lock();
            UpdateHierarchyValue();
        }

        void Unlock() {
            this_thread_hierarchy_value_ = previous_hierarchy_value_;
            internal_mutex_.unlock();
        }

        bool TryLock() {
            CheckForHierarchyViolation();
            if (!internal_mutex_.try_lock()) {
                return false;
            }
            UpdateHierarchyValue();
            return true;
        }
    
    private:
        std::mutex internal_mutex_;
        uint64_t const hierarchy_value_;
        uint64_t previous_hierarchy_value_;
        static thread_local uint64_t this_thread_hierarchy_value_;

        void CheckForHierarchyViolation() {
            if (this_thread_hierarchy_value_ <= hierarchy_value_) {
                throw std::logic_error("mutex hierarchy violated");
            }
        }    

        void UpdateHierarchyValue() {
            previous_hierarchy_value_ = this_thread_hierarchy_value_;
            this_thread_hierarchy_value_ = hierarchy_value_;
        }



    };

} // namespace core

#endif // CORE_HIERARCHICAL_MUTEXT_H_