# Spell Checker - Wagner-Fischer

This project is a simple spell-checking tool that uses the Wagner-Fischer algorithm to compute edit distances between words in an input text and a known dictionary. It provides both a C-based backend and a Python GUI frontend.

## Features

- Implements the **Wagner-Fischer algorithm** for Levenshtein distance calculation.
- GUI interface built with Python for ease of use.
- Reads text input from files and compares words against a dictionary.
- Highlights or suggests corrections for misspelled words.

## Project Structure

📁 DS_cp1/
├── dictionary.txt # List of valid dictionary words
├── main_gui.c # C source file for GUI integration
├── readFile.c / readFile.h # Functions to read and process input files
├── spell_gui.py # Python GUI frontend
├── wagner_fischer.c/.h # Implementation of the Wagner-Fischer algorithm
└── README.md # Project documentation

markdown
Copy
Edit

## Requirements

- C compiler (e.g., `gcc`)
- Python 3.x
- `tkinter` (for the GUI)

## How to Build and Run

### C Backend

1. Compile the C code:

```bash
gcc main_gui.c readFile.c wagner_fischer.c -o spell_checker
```
Run the compiled binary:
```
./spell_checker
```
Python GUI
Ensure tkinter is installed (it usually comes with Python):
```
python3 -m tkinter
```
Run the GUI:
```
python3 spell_gui.py
```
Algorithm Overview
The Wagner-Fischer algorithm is a dynamic programming method used to calculate the minimum number of operations (insertions, deletions, substitutions) required to transform one string into another. It's commonly used in spell-checking and DNA sequence alignment.
