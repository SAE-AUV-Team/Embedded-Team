/*
 * -------------------------------------------------------------------------
 * SAE AUV Team - Core Embedded Firmware (Sensor & Communications Hub)
 * -------------------------------------------------------------------------
 *
 * ARCHITECTURE OVERVIEW:
 * This microcontroller acts as the central data acquisition and communication
 * node. It is responsible for polling external sensors (depth, temperature, 
 * leak detection) and managing the CAN bus network. 
 * 
 * NOTE ON MOTOR CONTROL:
 * Thruster mixing, PWM generation, and 6-DOF vehicle stabilization are 
 * handled entirely by the Pixhawk. This file must NOT contain motor control 
 * logic. Its primary objective is routing clean telemetry to the Pixhawk 
 * via the CAN bus.
 * 
 * -------------------------------------------------------------------------
 */

// =========================================================================
// SECTION 1: HARDWARE ALIASES & PIN DEFINITIONS
// =========================================================================
// Define all physical pin connections here to prevent hardcoding later.
// - Define CAN Transceiver pins (RX, TX).
// - Define I2C pins for environmental sensors like depth (SDA, SCL).
// - Define SPI pins for high-speed sensors (MOSI, MISO, SCK, CS).
// - Define Analog pins for power monitoring (Battery voltage/current) or leak sensors.

// =========================================================================
// SECTION 2: CAN BUS CONFIGURATION & NODE IDs
// =========================================================================
// Define the CAN network parameters and address directory.
// - Define the global CAN baud rate (e.g., 500 kbps or 1 Mbps).
// - Define the CAN ID for this specific microcontroller node.
// - Define the target CAN IDs for the Pixhawk.
// - Define message structures and Data Length Codes (DLC) for telemetry packets.

// =========================================================================
// SECTION 3: SYSTEM INITIALIZATION (SETUP)
// =========================================================================
// The setup phase runs exactly once upon system boot.
// Task 1: Initialize Serial communication for local USB debugging.
// Task 2: Initialize the I2C/SPI buses and run self-tests on connected sensors.
// Task 3: Configure the CAN controller, set hardware filters to only accept 
//         relevant messages, and start the CAN interface.
// Task 4: Halt system and trigger error indicator if critical sensors or CAN fail to boot.

// =========================================================================
// SECTION 4: MAIN EXECUTION THREAD (LOOP)
// =========================================================================
// The main loop runs continuously. It must be non-blocking (avoid using delay()).
// Task 1: Poll depth, pressure, and environmental sensors at fixed time intervals.
// Task 2: Read battery management metrics (voltage, current consumption).
// Task 3: Check the CAN receive buffer for any incoming status requests, heartbeats, 
//         or mode-switch commands from the Pixhawk or companion computer.
// Task 4: Package the newly acquired sensor data into standard 8-byte CAN frames.
// Task 5: Transmit the updated telemetry CAN frames to the Pixhawk.

// =========================================================================
// SECTION 5: SENSOR ACQUISITION FUNCTIONS
// =========================================================================
// Create isolated, modular functions for each specific sensor.
// - Function to request, read, and scale pressure/depth data from the I2C sensor.
// - Function to read internal hull temperature and humidity.
// - Function to read leak detection probes.
// - Function to apply digital low-pass filtering to noisy analog sensor reads before transmission.

// =========================================================================
// SECTION 6: CAN PROTOCOL HANDLING FUNCTIONS
// =========================================================================
// Create modular functions for network communication.
// - Function to pack floating-point or integer sensor data into 8-byte CAN payloads.
// - Function to push telemetry frames onto the CAN TX mailbox.
// - Function to parse incoming CAN frames, extracting the ID and payload, 
//   and updating local state variables if the Pixhawk sends a command.
