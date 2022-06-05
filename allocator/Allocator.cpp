#include <map>
#include <cassert>
#include "Pool.cpp"

class Allocator {
private:
    using block_size = std::size_t;
    using block_count = std::size_t;
private:
    std::map<block_size, Pool *> map_block;
public:
    Allocator(std::initializer_list<std::pair<block_size, block_count>> init) {
        for (auto iter: init) {
            map_block[iter.first] = new Pool(iter.second, iter.first);
        }
    }

    template<typename T>
    class allocator {
    public:
        using value_type = T;
    public:
        Allocator *alloc = nullptr;
        int ptr_counter;
    public:
        explicit allocator(Allocator &allocator) : alloc(&allocator), ptr_counter(1) {}

        allocator(allocator &allocator): alloc(allocator.alloc), ptr_counter(allocator.ptr_counter) {
            ptr_counter += 1;
        }

        template<typename U>
         allocator(const allocator <U> &allocator): alloc(allocator.alloc), ptr_counter(allocator.ptr_counter) {
            ptr_counter += 1;
        }


        T *allocate(std::size_t size) {
            auto t = reinterpret_cast<T *>(alloc->map_block[sizeof(T) * size]->allocate(size * sizeof(T)));
            if (t == nullptr) {
                throw std::bad_alloc();
            }
            return t;
        }

        void deallocate(T *ptr, std::size_t size) {
            alloc->map_block[sizeof(T) * size]->deallocate(reinterpret_cast<void *>(ptr), size);
        }


        ~allocator() {
            if (ptr_counter == 0) {
                delete alloc;
            }

        }
    };

    ~Allocator() {
        for (auto item: map_block) {
            delete item.second;
        }
    }
};