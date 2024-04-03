# 3DViewer

Application for viewing 3D wireframe models in C++ in the object-oriented programming paradigm.
# About program
- Prepared full coverage of modules related to model loading and affine transformations with unit-tests
- There can be only one model on the screen at a time
- The program provides the ability to:
    - Load a wireframe model from an obj file (vertices and surfaces list support only).
    - Translate the model by a given distance in relation to the X, Y, Z axes.
    - Rotate the model by a given angle in relation to its X, Y, Z axes.
    - Scale the model by a given value.
- The graphical user interface contains:
    - A button to select the model file and a field to output its name.
    - A visualisation area for the wireframe model.
    - Button/buttons and input fields for translating the model.
    - Button/buttons and input fields for rotating the model.
    - Button/buttons and input fields for scaling the model.
    - Information about the uploaded model - file name, number of vertices and edges.
- The program correctly processes and allows user to view models with details up to 100, 1000, 10,000, 100,000, 1,000,000  vertices without freezing (inactivity of more than 0.5 seconds)
- The program allows customizing the type of projection (parallel and central)
- The program allows setting up the type (solid, dashed), color and thickness of the edges, display method (none, circle, square), color and size of the vertices
- The program allows choosing the background color
- Settings are saved between program restarts
- The program allows saving the captured (rendered) images as bmp and jpeg files.
- The program allows recording small screencasts - the current custom affine transformation of the loaded object into gif-animation (640x480, 10fps, 5s) by a special button
