#include "../builder/registers.h"
#include "../simulator/operations.h"

#include <stdio.h>

int main(void) {
    QuantumRegister *q = qregister_create(3);
    apply_gate_hadamard(q, 0);
    apply_cnot(q, 0, 1);
    apply_cnot(q, 1, 2);

    printf("GHZ state amplitudes (|000> through |111>):\n");
    qregister_print(q);
    qregister_free(q);
    return 0;
}
