#include "../builder/registers.h"
#include "../simulator/operations.h"

#include <stdio.h>

/*
 * Shor order-finding circuit for N = 15 and a = 2.
 * Eight counting qubits and four work qubits give a 12-qubit register.
 */
int main(void) {
    const int counting_qubits = 8;
    const int work_start = counting_qubits;
    const int work_qubits = 4;
    const int modulus = 15;
    const int base = 2;

    QuantumRegister *q = qregister_create(counting_qubits + work_qubits);

    /* Prepare |0...0>|1>, then create the counting-register superposition. */
    qregister_set_number(q, 1 << work_start);
    apply_n_hadamard(q, 0, counting_qubits);

    /* Controlled modular multiplication by a^(2^j) mod N. */
    for (int j = 0; j < counting_qubits; j++) {
        apply_controlled_prod_exp(q, j, work_start, work_qubits,
                                  base, modulus, 1LL << j);
    }

    apply_iqft(q, 0, counting_qubits);

    ClassicalRegister *measurement = cregister_create(counting_qubits);
    for (int j = 0; j < counting_qubits; j++) {
        qregister_measure(q, j, measurement, j);
    }

    printf("Shor order finding for N=%d, a=%d (%d qubits): measured phase index %lld\n",
           modulus, base, counting_qubits + work_qubits,
           (long long)cregister_calc_number(measurement));
    printf("Expected prominent phase indices: 0, 64, 128, 192\n");

    cregister_free(measurement);
    qregister_free(q);
    return 0;
}
