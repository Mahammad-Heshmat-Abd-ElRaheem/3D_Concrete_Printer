# 3D_Concrete_Printer
My graduation project was a 3D Concrete Printing (3DCP) machine capable of fabricating concrete structures in three dimensions, similar to the way conventional 3D printers work with plastic. The system was designed to automate layer-by-layer deposition of concrete material to create complex geometries efficiently and accurately.
# 🏗️ 3D Concrete Printer

## Overview

This project is a **3D Concrete Printer** capable of fabricating complex concrete structures using additive manufacturing techniques similar to conventional plastic 3D printers. The system integrates a **desktop application** for G-code preparation and an **embedded control firmware** running on an STM32 microcontroller. Together, they enable precise, automated, layer-by-layer deposition of concrete.

---

## 🎯 Project Objectives

- Develop an embedded system for accurate motion control of the concrete printing mechanism.
- Create a desktop application to translate user-generated G-code into printer-specific instructions.
- Ensure reliable, deterministic operation by avoiding runtime communication during printing.

---

## 🖥️ Desktop Application

The desktop application acts as a **bridge between user-generated G-code and the embedded firmware**. Its responsibilities include:

- **G-code Parsing**  
  - Read and interpret G-code files to extract geometric paths, extrusion rates, and printing parameters.
- **Instruction Generation**  
  - Convert standard G-code commands into a custom instruction set optimized for the embedded controller.
- **User Interface**  
  - Provide an intuitive interface for:
    - Loading and previewing G-code files.
    - Configuring printer settings.
    - Monitoring preparation steps.
- **Communication Strategy**  
  - To **eliminate potential communication failures** during sensitive motion operations, the system **does not rely on live data transmission** while printing. Instead, prepared instructions are transferred in advance to the embedded system.

---

## ⚙️ Embedded Firmware

The embedded firmware is developed for the **STM32F401CCU6 microcontroller** and is responsible for:

- Interpreting pre-generated instructions from the desktop application.
- Controlling stepper motors to execute precise movements in X, Y, and Z axes.
- Managing extrusion mechanisms to ensure consistent material flow.
- Coordinating motion sequences to construct the target structure layer by layer.

---

## 🛠️ Hardware Components

- **Microcontroller**: STM32F401CCU6
- **Motion System**: Stepper motors with drivers
- **Extruder**: Concrete extrusion system (custom design)
- **Mechanical Frame**: Gantry system for 3-axis motion control

*Note: Detailed mechanical designs, electrical schematics, and BOM are included in the `hardware/` directory.*

---

## 🗂️ Repository Structure

