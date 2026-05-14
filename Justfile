clean:
    qmk clean

compile: clean
    qmk compile --keyboard voyager --keymap custom
