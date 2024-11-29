# DUMSCPP_l4

_Created for the course "Development using modern C++ standards" V. N. Karazin Kharkiv National University_

"Image2" CMake linux program using C++17 standard.

---

# Image Class: Part 2 (Image2)

This project demonstrates the implementation of the **Strategy Pattern** to extend the functionality of the [`Image` class](https://github.com/DarkCard1nal/DUMSCPP_l3.git), enabling it to handle multiple image formats. The Strategy Pattern allows switching between different modes of operation dynamically. Specifically, the project supports grayscale images in **PGMA** format and color images in **PPM** format.

---

## Features

### 1. **Main Components**
- **Image Class**: A universal class for working with images.  
  - **Key Methods**:
    - `getRows()` and `getCols()`: Retrieve image dimensions.
    - `at(row, col)`: Access individual pixels.
    - `load()` and `save()`: Delegate file operations to the active strategy.
    - `setStrategy(strategy)`: Change the strategy for working with a specific image format.
  - **Data**: The class maintains a container (`pixels`) to store pixel data.

- **ImageFormatStrategy Interface**: An abstract interface that defines the methods:
  - `load(file)`: Reads an image file and initializes its dimensions and pixel data.
  - `save(file)`: Writes image data to a file.

- **PGMAStrategy**: Implements the strategy for handling **PGMA (Portable GrayMap ASCII)** files.
  - **Format Details**: Stores a single intensity value (0–255) for each pixel.
  - Provides methods to load and save grayscale images.

- **PPMStrategy**: Implements the strategy for handling **PPM (Portable PixMap)** files.
  - **Format Details**: Stores three intensity values (red, green, blue) for each pixel.
  - Provides methods to load and save color images.

---

## 2. **Program Logic**
The program dynamically selects the appropriate strategy to process files based on the file format:
1. **Reading an Image**:  
   - Selects a strategy (e.g., `PGMAStrategy`, `PPMStrategy`).
   - Uses the `load()` method of the selected strategy to read the image file.

2. **Processing an Image**:  
   - The `at()` method allows accessing and modifying individual pixels.

3. **Saving an Image**:  
   - The `save()` method of the current strategy writes the image data to a file.

---

## 3. **Alternative Implementation (Polymorphism Approach)**

In the `task4v2` folder, the project demonstrates an alternative implementation using **Polymorphism** instead of the Strategy Pattern. The `Image` class is split into specialized subclasses for each format, such as `PGMAImage` and `PPMImage`.

### Key Differences Between Approaches:

| Feature                | Strategy Pattern                                      | Polymorphism                                       |
|------------------------|-------------------------------------------------------|---------------------------------------------------|
| **Structure**          | One main class (`Image`) with strategies for formats. | Separate subclasses for each format.             |
| **Flexibility**        | Dynamically switch formats during runtime.            | Fixed format per instance (defined at creation). |
| **Ease of Extension**  | Add a new strategy for a new format.                  | Add a new subclass for a new format.             |
| **Code Reuse**         | Shared logic in the `Image` class.                    | Limited reuse; logic is distributed across classes. |
| **Runtime Behavior**   | Changes format with `setStrategy()`.                  | Requires creating a new object for a new format. |

---

## 4. **Advantages of Each Approach**
- **Strategy Pattern**:
  - More flexible for dynamic format changes.
  - Reduces the number of subclasses and keeps common functionality in the base class.
- **Polymorphism**:
  - Simpler for cases where formats are static or predefined.
  - Avoids external dependencies on strategy objects.

---

## Running the Program

### Compilation:
```bash
g++ -o task4 main.cpp PGMAStrategy.cpp PPMStrategy.cpp Image.cpp
g++ -o task4v2 main.cpp PGMAImage.cpp PPMImage.cpp
```

### Execution:
```bash
./task4
./task4v2
```

---

## Sample Output

### task4 (Strategy Pattern):
```
PGMA Image loaded successfully.
Image changed successfully:
255 0 255 0 255 ...
PGMA Image saved successfully.
PPM Image loaded successfully.
0 0 0 15 0 15 ...
PPM Image saved successfully.
```

### task4v2 (Polymorphism):
```
PGMA Image loaded successfully.
Image changed successfully:
255 0 255 0 255 ...
PGMA Image saved successfully.
PPM Image loaded successfully.
0 0 0 15 0 15 ...
PPM Image saved successfully.
```

---

## Summary

This project demonstrates two approaches—**Strategy Pattern** and **Polymorphism**—to manage multiple image formats. Each approach has unique strengths and is suitable for different use cases, balancing flexibility, extensibility, and simplicity.
