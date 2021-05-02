#include <stdint.h>
#include <stdbool.h>

struct naive_match_iter{
    const uint8_t *x; // String
    uint32_t n; // String length
    const uint8_t *p; // Pattern
    uint32_t m; // Pattern length
    uint32_t current_index;
};

struct match{
    uint32_t pos;
};

void init_naive_matcher_iter(struct naive_match_iter *iter, const uint8_t *x, uint32_t n, const uint8_t *p, uint32_t m){
    iter->x = x;
    iter->n = n;
    iter->p = p;
    iter->m = m;
    iter->current_index = 0;
}

bool next_naive_search(struct naive_match_iter *iter, struct match *match){
    uint32_t n = iter->n;
    uint32_t m = iter->m;
    const uint8_t *x = iter->x;
    const uint8_t *p = iter->p;

    if(m > n) return false;
    if(m == 0) return false;

    for(int32_t j = iter->current_index; j <= n-m; j++){
        uint32_t i = 0;
        while(i < m && x[j+i] == p[i]){
            i++;
        }
        if (i==m){
            iter->current_index = j+1;
            match->pos = j;
            return true;
        }
    }
    return false;
}

void dealloc_naive_match_iter(struct naive_match_iter *iter){
    
}