# Particle
Sketches for particle photon

# Electro

## Overview
This firmware uses the particle photon to create a wi-fi voltmeter.

## Usage

2 cloud variables are exposed: `voltage` and `maxvoltage`.
```shell
# Calculate and display maximum input voltage
particle variable get <photon-name> maxvoltage
```
```shell
# Read current voltage difference between positive and ground probes
particle variable get <photon-name> voltage
```

## Hardware

##### Parts used:
* [Particle Photon](https://store.particle.io/collections/photon) (x1)
* 82k ohm 1% tolerance resistor (x1)
* 10k ohm 1% tolerance resistor (x1)
* (Optional) Breadboard (x1)
* (Optional) Jumper wires (x4)

##### Wiring Diagram Example:

![Fritzing](./electro.png)

## Firmware
The photon analog input pins can take an input voltage of between 0 and 3.3 volts, and are 12bits giving a 4096 resolution. In order to reduce the input voltage to prevent damaging the photon, a voltage divider circuit is used. Depending on the resistor values used, the maximum safe input voltage in calculated.

* `vPin` variable can be changed to correspond to using photon inputs A0-A5.
* `vPow` variable can be adjusted based on individual photon reference voltage.
* `r1` can be adjusted if resistor 1 (82k ohm) is changed.
* `r2` can be adjusted if resistor 2 (10k ohm) is changed.
