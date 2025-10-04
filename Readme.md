# Ons - Dhikr Reminder Application

## Overview
**Ons** is a Dhikr Reminder application designed to help users consistently remember their spiritual remembrances (Adhkar) throughout the day.

## Project Structure
The application follows a modular architecture with three core files:

| File | Purpose |
|------|---------|
| `zikr.h` | Contains headers and method declarations |
| `zikr.cpp` | Implements the class methods |
| `main.cpp` | Handles Windows API, GUI, and main application logic |

## Core Features

### 1. Add Dhikr Method
- Allows users to add custom Dhikr to the list
- Provides flexibility for personal remembrances

### 2. Import Method
- Imports Adhkar from external files
- Separates data from code for easy maintenance
- Enables updates without modifying source code

### 3. Display Method
- Handles continuous, sequential display of Adhkar
- Ensures consistent reminders for the user

### 4. Reset Method
- Automatically restarts the Dhikr cycle
- Maintains continuous loop of reminders
- Ensures application runs perpetually

## User Interface
The application interface is documented in the **second-to-last slide** of the PowerPoint presentation available in this repository.

## Technical Implementation
- Built using Windows API for native performance
- Implements a guards system for data protection
- Modular design for maintainability and scalability