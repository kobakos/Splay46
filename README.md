# Splay46
![KBD_IMAGE](/readme_imgs/kbd_pic.jpeg)
## Build guide
***This keyboard requires soldering of really small smd components like USB Type C Receptacle(0.3mm pitch), Atmega32U4(0.8mm pitch), 0603(1608 in metric) sized capacitors/resistors, thus only recommended for experts.***

![Layers](/readme_imgs/layer_zusi.png)
 I will refer to these four sections of the case as bottom, mid-low , mid-hi, top, from bottom to top.
## Getting all the parts you'll need
- PCB(gerbers are in this repository. Hot-swappable version(only MX series) and ALPS compatible version(non hot-swappable) is available.)
- Components(check the BOM).
- Case(dxf is in this repository)
- Plate(dxf is in this repository. MX or ALPS)
- Gaskets *20
- M2 screws *28
- M2 spacers (length depends on the mid layer thickness) *14
- M6 nuts *8 (for tenting/tilting)
- M6 bolts *16 (for tenting/tilting)
- keyswitches * 46
### BOM

| Annotation(Silk) | Component                        | digikey product number    | 
| ---------------- | -------------------------------- | ------------------------- | 
| C1               | 10uf capacitor                   | 1276-1119-1-ND            | 
| C2,5,6           | 0.1uf capacitor                  | 1276-CL10B104KB8NNNLCT-ND | 
| C3,4             | 22pf capacitor                   | 478-1167-1-ND             | 
| C7               | 1uf capacitor                    | 276-1102-1-ND             | 
| R1,2             | 22ohm resistor                   | 311-22.0HRCT-ND           | 
| R3,4             | 10kohm resistor                  | 311-10KDCT-ND             | 
| R5,6             | 5.1kohm resistor                 | 311-5.10KHRCT-ND          | 
| Y1               | 16.0Mhz crystal                  | SER4069CT-ND              | 
| U1               | Atmega32U4                       | ATMEGA32U4-AURCT-ND       | 
| SW1              | Tactile switch                   | CKN10361CT-ND             | 
| D1-23            | smd Diode                        | SMMSD4148T1GOSCT-ND       | 
| J1               | USB type-c receptacle            | 2073-USB4105-GF-ACT-ND    | 
| J2               | TRS jack                         | CP-3502SJCT-ND            | 
| MX1-23           | Kailh MX switch socket(optional) | -                         | 
### Getting the case
This case was made to be stacked with 2, 3, 3, 3, 2.5, 3, 3 mm thick acryilc plate(from bottom to top). But if you are thinking of ordering the acrylics to elecrow, it will be costly to do so with these layer thicknesses, so instead you can set all layer's thickness as 3mm. You can use the whole_3030.dxf in that case.
### Spacer size/ length
The hex hole on the mid layer is a hexagon that circumscribes with a circle with 4.2mm radius, and the hole on the top/bottom layer is a circle with 2.2mm radius.
Spacer length should be the same as the thickness of the mid-hi layer + mid-low layer.
### Gasket thickness
Thickness of the gaskets depends on the mid-hi layer's thickness. If you are using 2.5mm plate and 3.0mm plate for the mid-hi layer with a 1.5mm thick plate, the gasket thickness would be 2mm. Generally, (gasket thickness) = ((mid-hi layer thickness) - (plate thickness)) /2
## Soldering the components onto the pcb(except the switches)
Place the components below to its corresponding silks and solder them. The placement of the MCU and the diode have to be done carefully accroding to the picture below. The rest of it doesn't care about placement angle as long as it matches the footprint. Check out some SMD soldering tutorials on youtube if you are worried about soldering these components.
Check if there are no soldering defects, and plug it in to the pc to see if the pcb is working properly.
## Placing the switches
Insert the switches to the plate, then solder(or just insert, if you are working on a hot-swappable pcb) them to the pcb.
## Flashing the firmware
Download the firmware in this repository and move it under QMK's keyboards folder. Check https://beta.docs.qmk.fm/using-qmk/guides/flashing/flashing how to flash. This keybaord use DFU as bootloader and EEPROM to define the handedness so for example if you are flashing the default firmware with the left hand side connected to the pc, you can do that by running ```make splay46:default:dfu-split-left```.
## Assembling the case
Stick the gaskets to the plate. Stack the first three layer (bottom and mid-low), place the plate and pcb on top of it. Place rest of the acrylics, adjust the placement, then screw them.
