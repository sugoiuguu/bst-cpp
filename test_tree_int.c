#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdint.h>
#include "tree.h"

#define VSIZE(V)  sizeof(V) / sizeof(V[0])

static void __print_nodes(tree_node_t *n)
{
    if (n != NULL) {
        __print_nodes(n->left);
        printf("%lu\n", *(uint64_t *)n->data);
        __print_nodes(n->right);
    }
}

static void print_nodes(tree_t *t)
{
    __print_nodes(t->root);
}

int main(void)
{
    uint64_t val;
    struct timespec ts;
    tree_t *tree = new_tree(compare_int, sizeof(uint64_t), 1L);

    timespec_get(&ts, TIME_UTC);
    srand(ts.tv_nsec);

    for (int i = 1; i <= 10; i++) {
        val = rand() % 100 + 1;
        tree_insert(tree, &val);
    }

    print_nodes(tree);
    destroy_tree(tree);

    return 0;
}