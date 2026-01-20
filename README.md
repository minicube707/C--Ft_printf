# 🖨️ ft_printf

## 📝 Description

**ft_printf** is a project from **School 42**.  
The goal is to recreate the behavior of the standard C `printf` function.  
This project helps deepen the understanding of variadic functions, formatting, and output handling in C.

---

## 🗂️ Architecture

This repository is divided into two subfolders:
- `Mandatory` for the mandatory part
- `Bonus` for the bonus part

---

## 🎯 Objectives

- Understand and use variadic functions
- Parse and handle format strings
- Manage different data types
- Write clean and norm-compliant C code (42 Norm)
- Handle memory properly

---

## 🛠️ Prototype

```c
int ft_printf(const char *format, ...);
```

### 🔍 Supported Conversions
The function supports the following format specifiers:

| Specifier | Description |
|:----------:|:------------|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address |
| `%d` | Decimal integer |
| `%i` | Integer |
| `%u` | Unsigned integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Percent sign |

--- 

### ⚙️ How It Works

- Parses the format string character by character
- Detects format specifiers and converts arguments accordingly
- Writes output to standard output
- Returns the total number of printed characters
- Mimics the behavior of the standard `printf`

---

### ⚙️ Compilation & Usage

```bash
make
```

Additional rules:

```bash
make clean
make fclean
make re
```

--- 

### 📐 Norm

- Fully compliant with the 42 Norm
- No forbidden functions used
- No memory leaks

### 👤 Author

- 42 Login: fmotte
- School: 42

--- 

### ✅ Status

✔️ Mandatory: validated  
⭐ Bonus: 122 / 125  