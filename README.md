# SimpleQuantumCircuitSimulator
A simple quantum circuit simulator base on efficient computation of the state vector

## Classic circuit examples

Build the examples with `make`, then run each program separately:

- `bin/examples/bell_state`
- `bin/examples/ghz_state`
- `bin/examples/deutsch_jozsa`
- `bin/examples/grover_search`
- `bin/examples/shor_order_finding`

The examples demonstrate Bell and GHZ entangled states, the Deutsch–Jozsa
algorithm, and one iteration of Grover search over a two-qubit search space.
Qubit 0 is the least significant bit in the simulator's state indices.
Measurement-based examples print one sampled result, so their output can vary
between runs.

The Shor order-finding example uses 12 qubits: an 8-qubit counting register
and a 4-qubit work register. It runs the order-finding circuit for `N = 15`
and `a = 2`; its measurement should be concentrated near phase indices 0, 64,
128, and 192. This demonstrates the quantum order-finding stage, with classical
factor extraction left as a separate step.
