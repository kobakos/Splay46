# [ag_kari] Build Guide
***This keyboard requires soldering of really small smd components like USB Type C Receptacle(0.3mm pitch), Atmega32U4(0.8mm pitch), 0603(1608 in metric) sized capacitors/resistors, thus only recommended for experts.***
## Get all the parts you'll need
- PCB(gerbers in this repository. Hot-swappable version(only MX series) and )
- Components(check the BOM). Switch sockets are not included in the BOM so if you are working on the hot-swappable pcb, don't forget to buy it.
- Case(dxf is in this repository)
- Plate(dxf is in this repository)
- Gaskets
- M2 screws
- M2 spacers
- M6 nuts
- M6 bolts
- soldering kit(Using flux is strongly recommended)
### Getting the case
This case was intended to stack like the image below, but it'll take a lot of cost to do so,
## Soldering the components onto the pcb(except the switches)
Place the components below to its corresponding silks and solder them. The placement of the MCU and the diode have to be done carefully accroding to the picture below. The rest of it doesn't care about placement angle as long as it matches the footprint. Check out some SMD soldering tutorials on youtube if you are worried about soldering these components.
Check if the pcb is working after soldering the components by plugging it in to the pc.
### Trouble shooting
- Check if there are no solder joints using a loupe, especially within the MCU and the USB connector's legs.
- Sometimes SMD component is not soldered to the pads even though if it looks like it is.
- Check if the crystal is soldered properly.
- If the soldering looks perfect and the pc won't recognize the board, it can be a problem about the MCU's firmware. Flash a new firmware to it by ISP flashing.
## Placing the switches
Insert the switches to the plate, then solder(or just insert, if you are working on hot-swappable version) them to the pcb.
## Assembling the case
Stick the gaskets onto the plate. Stack the acrylics like this and place the plate and pcb on top of it. Place the rest of the acrylics and adjust the placement, then screw them.
