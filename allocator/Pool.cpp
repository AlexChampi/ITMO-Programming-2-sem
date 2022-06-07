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

    [[nodiscard]] Chunk *create_chuncks(size_t size) const {
        auto *first_chunk = new Chunk[chunks_count * size];
        auto *chunk = first_chunk;
        for (std::size_t i = 0; i < chunks_count; ++i) {
            chunk->next = new Chunk(*(first_chunk + i));
            chunk = chunk->next;
        }
        chunk->next = nullptr;
        return first_chunk;
    }

public:
    Pool(std::size_t chunks_count, std::size_t size)
            : chunks_count(chunks_count),
              cur_chunk(create_chuncks(size)),
              begin(cur_chunk) {}

    void *allocate(std::size_t size) {
        Chunk *chunk = cur_chunk;
        cur_chunk = cur_chunk->next;
        return chunk;
    }

    void deallocate(void *ptr, std::size_t size) {
        reinterpret_cast<Chunk *>(ptr)->next = cur_chunk;
        cur_chunk = reinterpret_cast<Chunk *>(ptr);
    }

    ~Pool() {
        delete[] begin;
    }

};

