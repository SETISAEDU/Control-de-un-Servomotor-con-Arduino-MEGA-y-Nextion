# Control-de-un-Servomotor-con-Arduino-MEGA-y-Nextion

## Nextion NX3224T028_011

Las pantallas táctiles LCD de Nextion son ideales para Arduinos porque la mayoría de sus funcionalidades y procesos son independientes en la pantalla. La comunicación con un Arduino es a través de un puerto UART serie. La ventaja es que el Arduino no utiliza muchos recursos o pines que se ocupan de una pantalla táctil de alta resolución, simplemente envía comandos serie a la pantalla o recibe notificaciones de eventos como pulsaciones de botones.

# Creando un botón

![Adding a button](https://raw.githubusercontent.com/SETISAEDU/Control-de-un-Servomotor-con-Arduino-MEGA-y-Nextion/master/Button_Nextion.jpg)

El editor Nextion tiene componentes masivos tales como [botones](https://www.itead.cc/wiki/Nextion_Editor_Quick_Start_Guide#Button), texto, barra de progreso, slider, panel de instrumentación, para enriquecer el diseño de su interfaz. Para agregar un botón realizamos los siguientes pasos:

1. Abrimos el editor de Nextion
2. Creamos un nuevo proyecto de trabajo
3. Seleccionamos la pantalla Nextion con la que vamos a trabajar (Modelo, Detalles y Orientación)
4. Creamos la fuente de letras (Consulte el siguiente [tutorial](https://www.itead.cc/wiki/Nextion_Editor_Quick_Start_Guide#Tool))
5. En el cuadro Toolbox seleccionamos Button
6. Seleccionamos el área de la pantalla donde insertamos el botón.
7. En la tabla de atributos modifcamos **solid color** por **crop image**
8. en el atributo **picc** seleccionamos la imagen del botón sin presionar 
9. En el atributo **picc2** seleccionamos la imagen del botón presionado
10. En la tabla de eventos podemos establecer acciones a realizar cuando se presione el botón
11. Al marcar la casilla **Send Component ID**, la Nextion enviará identificadores del botón presionado.

# Diagrama de conexión

Conecte los elementos como se muestra en el siguiente diagrama:
![Schematic](https://raw.githubusercontent.com/SETISAEDU/Control-de-un-Servomotor-con-Arduino-MEGA-y-Nextion/master/Nextion_Arduino_Servo_bb.png)

# Código de programación Arduino

Cargue el código `ControlServo_Nextion.ino` al Arduino MEGA, para recibir comando de acción de la Nextion y control la direccion y velocidad de giro del servomotor.

# Cargando el firmware a la pantalla NX3224T028_011

Guarde en una memoria microSD con formato **FAT 32** el firmware generado `ServoControl_Arduino.tft` y realice el procedimiento de programación como se muestra en el siguiente [tutorial](https://www.itead.cc/wiki/Nextion_Editor_Quick_Start_Guide#Flash_Project_firmware_from_SD_card).

## Menú para el control del Servomotor

En el primer menú podemos escoger que accion relizar: Controlar el sentido de giro y la velocidad de giro.
![Main_menu](https://raw.githubusercontent.com/SETISAEDU/Control-de-un-Servomotor-con-Arduino-MEGA-y-Nextion/master/Recursos%20Visuales%20de%20Dise%C3%B1o/Main%20Menu/Not_Selected.jpg) 

En el segundo menú se encuentran dos botones con los que podemos hacerlo girar a la izquierda o derecha.
![Sweep_menu](https://github.com/SETISAEDU/Control-de-un-Servomotor-con-Arduino-MEGA-y-Nextion/blob/master/Recursos%20Visuales%20de%20Dise%C3%B1o/Sweep%20Control/Not_Selected.jpg)

En el tercer menú podremos apreciar una barra de progreso junto con dos botones que nos permite controlar la velocidad con la que se efectúan los giros en el servomotor.
![Speed_menu](https://raw.githubusercontent.com/SETISAEDU/Control-de-un-Servomotor-con-Arduino-MEGA-y-Nextion/master/Recursos%20Visuales%20de%20Dise%C3%B1o/Speed%20Control/Not_Selected.jpg)
