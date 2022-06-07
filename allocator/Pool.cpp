#include <iostream>


class Pool {
private:
    struct Chunk {
        Chunk *next;
    };
private:
    std::size_t chunks_count;
    Chunk *begin = nullptr;
    Chunk *cur_chunk = nullptr;
//    static int ptr_counter;

public:
    Pool(std::size_t chunks_count, std::size_t size) : chunks_count(chunks_count) {
        begin = new Chunk[chunks_count * size];
        auto *chunk = begin;
        for (std::size_t i = 0; i < chunks_count; ++i) {
            chunk->next = new Chunk(*(begin + i));
            chunk = chunk->next;
        }
        chunk->next = nullptr;
        cur_chunk = begin;
    }

    Chunk *allocate(std::size_t size) {
        Chunk *chunk = cur_chunk;
        cur_chunk = cur_chunk->next;
        return chunk;
    }

    void deallocate(void *ptr, std::size_t size) {
        reinterpret_cast<Chunk *>(ptr)->next = cur_chunk;
        cur_chunk = reinterpret_cast<Chunk *>(ptr);
    }

    ~Pool() {
//        std::cout << begin << " " << cur_chunk;
        delete[] begin;
    }

};

