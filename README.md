# matlabd
Run Matlab as a daemon in the background, sending it commands through a FIFO.

To start a Matlab instance if one hasn't been started already, use `matlabd start`. To stop one ues `matlabd stop`.
To send a command to an instance, use `matlabd run [cmd]`.

## Installation

Run `make install` and follow the instructions about modifying your shell startup script and `startup.m`.
