#include "../builder/registers.h"
#include "../simulator/operations.h"

#include <stdio.h>

static bool marked_state(int64 value) {
    return value == 3;
}

int main(void) {
    /* Search a two-qubit space with the single marked state |11>. */
    QuantumRegister *q = qregister_create(2);
    apply_n_hadamard(q, 0, 2);
    apply_oracle_phase(q, 0, 2, marked_state);
    apply_diffusion(q, 0, 2);

    ClassicalRegister *result = cregister_create(2);
    qregister_measure(q, 0, result, 0);
    qregister_measure(q, 1, result, 1);
    printf("Grover search measured: %lld (target: 3)\n",
           (long long)cregister_calc_number(result));

    cregister_free(result);
    qregister_free(q);
    return 0;
}
