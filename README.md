# miniRT (executable)
**map directory contain sample map for testing. User can create his own map (juste follow the syntaxe)**
## Run

```bash
./miniRT <scene_file.rt>
```

Example:

```bash
./miniRT map/map.rt
```

## `scenes/sample.rt` (scene file)

A `.rt` file is a plain text file where **each line describes one element** of the scene:

- `A` : Ambient light
- `C` : Camera
- `L` : Light
- `sp` : Sphere
- `pl` : Plane
- `cy` : Cylinder

Each element line is followed by its values (position, direction, size, color, etc.).

## Controls (keyboard / mouse)

- `ESC` : quit

### Mouse
- **Left click** : select an object
- **Left click + drag + release** : move the selected object
- **Mouse wheel** : zoom the camera

### Keyboard
- `c` / `l` : switch/select the object you want to edit
- `d` / `h` : change display mode
- **Arrow keys** : move the selected object
- `+` / `-` (keypad) : increase or decrease the diameter d (height h) of selected object

### Rotate (X / Y / Z)
Rotation works when the selected element has an orientation (for example **camera**, **plane**, or **cylinder**).

- Use the **numeric keypad rotation keys** to rotate the selected element by steps around:
  - **X axis 1 2**
  - **Y axis 4 5**
  - **Z axis 7 8**


