# SAE AUV Team - Embedded Systems Firmware

Welcome to the central embedded systems repository for the SAE AUV Team. This repository maintains the core low-level C++ firmware powering the 6-degree-of-freedom (6-DOF) Autonomous Underwater Vehicle.

---

## 🛠️ Embedded Team Scope & Responsibilities

The Embedded division manages the interface between high-level autonomous planners and low-level physical actuators. Key focus areas include:

1. **Microcontroller Firmware Development**
   * Developing clean, non-blocking C++ code for STM32 (ARM Cortex-M) and ESP32 targets.
   * Managing timers, hardware interrupts (ISRs), Watchdog timers, and hardware peripherals (UART, SPI, I2C, CAN).

2. **Communication & Network Protocols**
   * Defining and managing custom CAN message frames.
   * Developing CAN bus transceivers, frame parsing engines, and error handling for multi-node vehicle telemetry.

3. **Motion Control & Actuation**
   * Generating precision PWM signals for Electronic Speed Controllers (ESCs).
   * Implementing thruster mixing algorithms mapping 6-DOF surge, sway, heave, roll, pitch, and yaw commands into individual motor thrust values.

4. **Sensor Acquisition & Conditioning**
   * Interfacing depth/pressure sensors, IMUs, internal temperature/humidity monitors, and battery monitoring systems.
   * Implementing digital filtering (moving average, low-pass, complementary/Kalman filters) for noise reduction.

5. **Hardware-in-the-Loop (HIL) & Bench Testing**
   * Verifying real-time signal integrity using oscilloscopes, logic analyzers, and test benches prior to wet tests.

---

## 📋 Comprehensive Contribution & Setup Guide

> **Important Policy:** Direct pushes and force pushes to the `main` branch are disabled. All modifications must go through a branch-and-pull-request workflow and receive approval from the Embedded Lead.

### Step 1: Install Required Tools
1. **GitHub Desktop:** Download and install [GitHub Desktop](https://desktop.github.com/). This provides a visual interface for managing your code.
2. **Code Editor:** I recommend using [Arduino IDE](https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.10_Windows_64bit.exe) for editing the C++ firmware files.
3. **Proteus Design Suite:** Install Proteus for local schematic capture and microcontroller simulation.
4. **Proteus Microcontroller Package:** Proteus does not include ESP32 or STM32 models by default. 
   * Download the required ESP32/STM32 Proteus Library Package [ESP32 Package](https://images.theengineeringprojects.com/document/main/2023/07/esp32-library-for-proteus.zip).
   * Extract the `.IDX` and `.LIB` files.
   * Paste them into the Proteus library directory: `C:\ProgramData\Labcenter Electronics\Proteus 8 Professional\LIBRARY`.
5. **Online Circuit Designer:** Use [Wokwi](https://wokwi.com/) (ideal for ESP32/Arduino simulation) or [Falstad](https://www.falstad.com/circuit/) (for quick analog/digital logic tests) for rapid browser-based prototyping before moving to physical hardware.

### Step 2. Authenticate GitHub Desktop
1. Launch GitHub Desktop.
2. Navigate to:
   * **Windows:** `File` > `Options` > `Accounts`
   * **macOS:** `GitHub Desktop` > `Settings` > `Accounts`
3. Click **Sign in** next to GitHub.com.
4. Select **Continue with Browser**, log into your GitHub account, and click **Authorize desktop**.
5. Under `Git` in the same Options menu, confirm that your **Name** and **Email** match your GitHub profile identity.

---

### Phase 2: Cloning the Repository

1. Open GitHub Desktop.
2. Click `File` > `Clone repository...` (or press `Ctrl + Shift + O` / `Cmd + Shift + O`).
3. Click the **URL** tab.
4. Paste the repository URL:
5. 5. Set the **Local path** to a clean development directory (e.g., `C:\Robotics\auv-embedded-firmware` or `~/projects/auv-embedded-firmware`).
6. Click **Clone**.

---

### Phase 3: Creating and Managing Feature Branches

Never write code directly on the `main` branch. Always work inside a scoped feature branch.

#### 1. Sync the Latest Changes
Before branching, make sure your local copy of `main` is current:
1. In GitHub Desktop, set **Current Branch** to `main`.
2. Click **Fetch origin** (or **Pull origin** if updates are pending) in the top-right toolbar.

#### 2. Create Your Feature Branch
1. Click the **Current Branch** dropdown menu.
2. Click **New Branch**.
3. Apply standard branch naming conventions:
* `feature/<subsystem>-<description>` (e.g., `feature/can-parser`, `feature/thruster-mixing`)
* `fix/<subsystem>-<bug>` (e.g., `fix/imu-timeout`, `fix/pwm-drift`)
* `docs/<topic>` (e.g., `docs/pinout-mapping`)
4. Confirm base branch is set to `main`, then click **Create Branch**.
5. Click **Publish branch** in the top bar to register this branch on GitHub.

---

### Phase 4: Editing and Verifying Code

1. Open the cloned folder in VS Code (`File` > `Open Folder...`).
2. Make your code changes in the appropriate directory (e.g., `src/`, `include/`, or `drivers/`).
3. Build the project locally using your compiler or PlatformIO environment to ensure:
* There are no syntax errors or unresolved includes.
* No unused variables or compiler warnings remain unaddressed.
4. Save all modified files (`Ctrl + S` or `Cmd + S`).

---

### Phase 5: Committing Your Work

1. Switch back to GitHub Desktop.
2. In the left panel under **Changes**, verify the list of modified, added, or deleted files.
3. Click on individual files to inspect the line-by-line diffs:
* Green lines indicate additions.
* Red lines indicate removals.
4. Check the boxes next to files you want to include in this specific commit.
5. In the bottom-left panel:
* **Title (Required):** Write a concise summary in imperative tense (e.g., `Add CAN mailbox filter setup for STM32F4`).
* **Description (Optional but encouraged):** Outline specific changes, register calculations, or dependencies.
6. Click **Commit to [your-branch-name]**.

---

### Phase 6: Pushing Changes and Submitting a Pull Request (PR)

#### 1. Push to Remote
1. Click **Push origin** in the top-right toolbar of GitHub Desktop.
2. Ensure the progress bar completes and the button changes to "Fetch origin".

#### 2. Open a Pull Request
1. Click the **Create Pull Request** button that appears in GitHub Desktop, or open the repository page on the GitHub web interface.
2. On GitHub, verify the branch mapping:
* **Base:** `main`
* **Compare:** `feature/your-branch-name`
3. Enter a clear PR title and fill out the summary:
* **Summary of Changes:** What logic was added or modified?
* **Hardware Tested On:** e.g., ESP32-WROOM-32, STM32F407, Bench test, or Simulator.
* **Known Limitations/Issues:** Any edge cases not yet covered.
4. On the right sidebar:
* Under **Reviewers**, select the Embedded Lead.
* Under **Labels**, apply relevant tags (e.g., `firmware`, `hardware-test-pending`).
5. Click **Create pull request**.

---

### Phase 7: Addressing Review Feedback & Updating the PR

If the reviewer requests changes or updates during code review:
1. Do **not** close the PR or create a new branch.
2. Open your local editor on your current feature branch, make the requested adjustments, and save.
3. Open GitHub Desktop, commit the new updates, and click **Push origin**.
4. GitHub automatically appends the new commit to your active Pull Request.
5. Notify the reviewer once corrections are complete.

---

### Phase 8: Cleaning Up After Merge

Once your PR has been merged into `main` by the Lead:
1. Open GitHub Desktop.
2. Switch your branch back to `main`.
3. Click **Pull origin** to download your newly merged code to your local machine.
4. Open the **Current Branch** menu, right-click your old feature branch, and select **Delete...** to keep your local workspace clean.
