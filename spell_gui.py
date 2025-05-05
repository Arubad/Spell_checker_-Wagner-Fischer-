import tkinter as tk
from tkinter import scrolledtext
import subprocess

def check_spelling():
    input_text = entry.get()
    if not input_text.strip():
        result_text.delete('1.0', tk.END)
        result_text.insert(tk.END, "Please enter some text.")
        return

    try:
        # Run the compiled C program with the input
        result = subprocess.run(
            ['./spellchecker'],  # Use 'spellchecker.exe' on Windows
            input=input_text.encode(),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=20
        )

        output = result.stdout.decode()
        result_text.delete('1.0', tk.END)
        result_text.insert(tk.END, output)

    except subprocess.TimeoutExpired:
        result_text.insert(tk.END, "Spell checker timed out.")
    except Exception as e:
        result_text.insert(tk.END, f"Error: {e}")

# --- GUI Setup ---
root = tk.Tk()
root.title("Spell Checker")

tk.Label(root, text="Enter your sentence:").pack(pady=5)
entry = tk.Entry(root, width=60)
entry.pack(pady=5)

tk.Button(root, text="Check Spelling", command=check_spelling).pack(pady=5)

tk.Label(root, text="Suggestions:").pack(pady=5)
result_text = scrolledtext.ScrolledText(root, width=70, height=20)
result_text.pack(pady=5)

root.mainloop()
