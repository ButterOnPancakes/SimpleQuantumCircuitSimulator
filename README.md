# SimpleQuantumCircuitSimulator
A simple quantum circuit simulator base on efficient computation of the state vector

## Classic circuit examples

Build the examples with `make`, then run each program separately:

- `bin/examples/bell_state`
- `bin/examples/ghz_state`
- `bin/examples/deutsch_jozsa`
- `bin/examples/grover_search`

The examples demonstrate Bell and GHZ entangled states, the Deutsch–Jozsa
algorithm, and one iteration of Grover search over a two-qubit search space.
Qubit 0 is the least significant bit in the simulator's state indices.
Measurement-based examples print one sampled result, so their output can vary
between runs.
