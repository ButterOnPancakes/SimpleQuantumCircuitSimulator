#include "../builder/registers.h"
#include "../simulator/operations.h"

#include <stdio.h>

int main(void) {
    QuantumRegister *q = qregister_create(2);
    apply_gate_hadamard(q, 0);
    apply_cnot(q, 0, 1);

    printf("Bell state amplitudes (|00>, |01>, |10>, |11>):\n");
    qregister_print(q);
    qregister_free(q);
    return 0;
}
