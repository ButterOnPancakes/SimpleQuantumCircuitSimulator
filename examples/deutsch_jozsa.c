#include "../builder/registers.h"
#include "../simulator/operations.h"

#include <stdio.h>

static bool balanced_function(int64 value) {
    return (value & 1) != 0;
}

int main(void) {
    /* Two input qubits and one |1> ancilla; f(x) = x[0] is balanced. */
    QuantumRegister *q = qregister_create(3);
    qregister_set_number(q, 1 << 2);
    apply_n_hadamard(q, 0, 3);
    apply_oracle_ancilla(q, 0, 2, 2, balanced_function);
    apply_n_hadamard(q, 0, 2);

    ClassicalRegister *result = cregister_create(2);
    qregister_measure(q, 0, result, 0);
    qregister_measure(q, 1, result, 1);
    printf("Deutsch–Jozsa input measurement: %lld (nonzero means balanced)\n",
           (long long)cregister_calc_number(result));

    cregister_free(result);
    qregister_free(q);
    return 0;
}
