Configuration.h
// The core and default settings of Marlin live in the Configuration.h file.
// Most of these settings are fixed.
// Once you compile Marlin, that’s it.
// To change them you need to re-compile.
// However, several items in Configuration.h only provide defaults

// -factory settings- *************************************************
// that can be changed via the user interface, stored on EEPROM and reloaded or restored to initial values.
// Settings that can be changed and saved to EEPROM are marked with . Options marked with  can be changed from the LCD controller.
// Settings saved in EEPROM persist across reboots and still remain after flashing new firmware, so always send M502, M500 (or “Reset EEPROM” from the LCD) after flashing.
// This section follows the order of settings as they appear.
// The order isn’t always logical, so “Search In Page” may be helpful.
// We’ve tried to keep descriptions brief and to the point.
// For more detailed information on various topics, please read the main articles and follow the links provided in the option descriptions.

// Configuration versioning *************************************************
#define CONFIGURATION_H_VERSION 020005 // Marlin now checks for a configuration version and won’t compile without this setting. If you want to upgrade from an earlier version of Marlin, add this line to your old configuration file. During compilation, Marlin will throw errors explaining what needs to be changed.

//Firmware Info *************************************************

// STRING_CONFIG_H_AUTHOR is shown in the Marlin startup message to identify the author (and optional variant) of the firmware.
// Use this setting as a way to uniquely identify your custom configurations.
// The startup message is printed whenever the board (re)boots.
#define STRING_CONFIG_H_AUTHOR "(none, default config)"

#define SHOW_BOOTSCREEN // SHOW_BOOTSCREEN enables the boot screen for LCD controllers.
// #define SHOW_CUSTOM_BOOTSCREEN // SHOW_CUSTOM_BOOTSCREEN shows the bitmap in Marlin/_Bootscreen.h on startup.
// #define CUSTOM_STATUS_SCREEN_IMAGE // CUSTOM_STATUS_SCREEN_IMAGE shows the bitmap in Marlin/_Statusscreen.h on the status screen.

// Hardware Info *************************************************
// Serial Port
// The index of the on-board serial port that will be used for primary host communication.
// Change this if, for example, you need to connect a wireless adapter to non-default port pins.
// The first serial port (-1 or 0) will always be used by the Arduino bootloader regardless of this setting.
#define SERIAL_PORT 0

// Enable this if your board has a secondary serial port.
// Serial port -1 is the USB emulated serial port, if available.
#define SERIAL_PORT_2 -1

// Baud Rate *************************************************
// The serial communication speed of the printer should be as fast as it can manage without generating errors.
// In most cases 115200 gives a good balance between speed and stability.
// Start with 250000 and only go lower if “line number” and “checksum” errors start to appear.
// Note that some boards (e.g., a temperamental Sanguinololu clone based on the ATMEGA1284P) may not be able to handle a baud rate over 57600.
// Allowed values: 2400, 9600, 19200, 38400, 57600, 115200, 250000.
#define BAUDRATE 115200

// Bluetooth *************************************************
// #define BLUETOOTH // Enable the Bluetooth serial interface. For boards based on the AT90USB.

// Motherboard *************************************************
// The most important setting is Marlin is the motherboard.
// The firmware needs to know what board it will be running on so it can assign the right functions to all pins and take advantage of the full capabilities of the board.
// Setting this incorrectly will lead to unpredictable results.

// Using boards.h as a reference, replace BOARD_RAMPS_14_EFB with your board’s ID.
// The boards.h file has the most up-to-date listing of supported boards - check there first if you don’t see yours listed here.
// The Sanguino board requires adding “Sanguino” support to Arduino IDE.
// Open Preferences and locate the Additional Boards Manager URLs field.
// Copy and paste this source URL. Then use Tools > Boards > Boards Manager to install “Sanguino” from the list.
// An internet connection is required. (Thanks to “Dust’s RepRap Blog” for the tip.)
#define MOTHERBOARD BOARD_STM32F103RE

// Custom Machine Name *************************************************
// This is the name of your printer as displayed on the LCD and by M115.
// For example, if you set this to “My Delta” the LCD will display “My Delta ready” when the printer starts up.
#define CUSTOM_MACHINE_NAME "Ender 3-PRO"

// Machine UUID *************************************************
// A unique ID for your 3D printer.
// A suitable unique ID can be generated randomly at uuidtools.com.
// Some host programs and slicers may use this identifier to differentiate between specific machines on your network.
//#define MACHINE_UUID "00000000-0000-0000-0000-000000000000"

// Extruder Info *************************************************
// This value, from 0 to 6, defines how many extruders (or E steppers) the printer has.
// By default Marlin will assume separate nozzles all moving together on a single carriage.
// If you have a single nozzle, a switching extruder, a mixing extruder, or dual X carriages, specify that below.
// This value should be set to the total number of E stepper motors on the machine, even if there’s only a single nozzle.
#define EXTRUDERS 1

// Filament Diameter *************************************************
// This is the “nominal” filament diameter as written on the filament spool (1.75, 2.85, 3.0).
// If you typically use 1.75mm filament, but physically measure the diameter as 1.70mm,
// you should still use 1.75 if that’s what you have set in your slicer.
// This value is used by Marlin to compensate for Filament Width when printing in volumetric mode (See M200),
// and by the Unified Bed Leveling command G26 when printing a test grid.
// You can override this value with M404 W.
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// Single Nozzle *************************************************
// Enable SINGLENOZZLE if you have an E3D Cyclops or any other “multi-extruder” system that shares a single nozzle.
// In a single-nozzle setup, only one filament drive is engaged at a time,
// and each needs to retract before the next filament can be loaded and begin purging and extruding.
#define SINGLENOZZLE


// Průša MK2 Single Nozzle Multi-Material Multiplexer
// Enabling MK2_MULTIPLEXER allows one stepper driver on a control board to drive two to eight stepper motors, one at a time.
//#define MK2_MULTIPLEXER
  //#define E_MUX0_PIN 40  // Always Required
  //#define E_MUX1_PIN 42  // Needed for 3 to 8 inputs
  //#define E_MUX2_PIN 44  // Needed for 5 to 8 inputs
// Override the default DIO selector pins.

// Průša MMU2
// Enable support for the Průša Multi-material unit 2.
// This requires a free serial port on your printer board.
//  To use the MMU2 you also have to
// #define PRUSA_MMU2

// Mixing Extruder *************************************************

// A Mixing Extruder uses two or more stepper motors to drive multiple filaments into a mixing chamber,
// with the mixed filaments extruded from a single nozzle. This option adds the ability to set a mixture,
// to save mixtures, and to recall mixtures using the T command. The extruder still uses a single E axis,
// while the current mixture is used to determine the proportion of each filament to use.
// An “experimental” G1 direct mixing option is included.
// MIXING_EXTRUDER enables M163 - set mix factor, M164 - save mix, and M165 - set mix.

//#define MIXING_EXTRUDER
#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 2        // Number of steppers in your mixing extruder
  #define MIXING_VIRTUAL_TOOLS 16  // Use the Virtual Tool method with M163 and M164
  //#define DIRECT_MIXING_IN_G1    // Allow ABCDHI mix factors in G1 movement commands
#endif

// Hotend Offsets *************************************************

// Hotend offsets are needed if your extruder has more than one nozzle.
// These values specify the offset from the first nozzle to each nozzle.
// So the first element is always set to 0.0. The next element corresponds to the next nozzle, and so on.
// Add more offsets if you have 3 or more nozzles.
//#define HOTEND_OFFSET_X { 0.0, 20.00 } // (mm) relative X-offset for each nozzle
//#define HOTEND_OFFSET_Y { 0.0, 5.00 }  // (mm) relative Y-offset for each nozzle
//#define HOTEND_OFFSET_Z { 0.0, 0.00 }  // (mm) relative Z-offset for each nozzle

// Power Supply *************************************************

// ATX *************************************************
// This option allows the controller board to switch the power supply 12V on and off with M80 and M81. Requires PS_ON_PIN.
// Enable this if you don’t want the power supply to switch on when you turn on the printer.
// This is for printers that have dual power supplies. For instance some setups have a separate power supply for the heaters.
// In this situation you can save power by leaving the power supply off until needed.
// If you don’t know what this is leave it.

//#define PSU_CONTROL
//#define PSU_NAME "Power Supply"
#if ENABLED(PSU_CONTROL)
  #define PSU_ACTIVE_HIGH false // Set 'false' for ATX (1), 'true' for X-Box (2)
  //#define PS_DEFAULT_OFF      // Keep power off until enabled directly with M80
  //#define AUTO_POWER_CONTROL  // Enable automatic control of the PS_ON pin
  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS           // Turn on PSU if fans need power
    #define AUTO_POWER_E_FANS
    #define AUTO_POWER_CONTROLLERFAN
    #define AUTO_POWER_CHAMBER_FAN
    //#define AUTO_POWER_E_TEMP        50 // (°C) Turn on PSU over this temperature
    //#define AUTO_POWER_CHAMBER_TEMP  30 // (°C) Turn on PSU over this temperature
    #define POWER_TIMEOUT 30
  #endif
#endif
//#define PS_DEFAULT_OFF


// Thermometer *************************************************
// Temperature Sensors
// Temperature sensors are vital components in a 3D printer.
// Fast and accurate sensors ensure that the temperature will be well controlled,
// to keep plastic flowing smoothly and to prevent mishaps.
// Use these settings to specify the hotend and bed temperature sensors.
// Every 3D printer will have a hotend thermistor, and most will have a bed thermistor.
// The listing above these options in Configuration.h contains all the thermistors and thermocouples that Marlin knows and supports.
// Try to match your brand and model with one of the sensors in the list.
// If no match is found, use a profile for a similar sensor of the same brand, or try “1” – the generic profile.
// Each profile is calibrated for a particular temperature sensor so it’s important to be as precise as possible.
// It is crucial to obtain accurate temperature measurements.
// As a last resort, use 100k thermistor for TEMP_SENSOR and TEMP_SENSOR_BED but be highly skeptical of the temperature accuracy.
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_CHAMBER 0

// Dummy thermistor constant temperature readings, for use with 998 and 999
// Marlin provides two dummy sensors for testing purposes.
// Set their constant temperature readings here.
#define DUMMY_THERMISTOR_998_VALUE 25
#define DUMMY_THERMISTOR_999_VALUE 100

// Enable this option to use sensor 1 as a redundant sensor for sensor 0.
// This is an advanced way to protect against temp sensor failure.
// If the temperature difference between sensors exceeds MAX_REDUNDANT_TEMP_SENSOR_DIFF Marlin will abort the print and disable the heater.
//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

// Temperature Stability *************************************************
// Extruders must maintain a stable temperature for TEMP_RESIDENCY_TIME before M109 will return success and start the print.
//Tune what “stable” means using TEMP_HYSTERESIS and TEMP_WINDOW.
#define TEMP_RESIDENCY_TIME 10  // (seconds)
#define TEMP_HYSTERESIS 3       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW 1           // (degC) Window around target to start the residency timer x degC early.

// The bed must maintain a stable temperature for TEMP_BED_RESIDENCY_TIME before M109 will return success and start the print.
// Tune what “stable” means using TEMP_BED_HYSTERESIS and TEMP_BED_WINDOW.
#define TEMP_BED_RESIDENCY_TIME 10  // (seconds)
#define TEMP_BED_HYSTERESIS 3       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_BED_WINDOW 1           // (degC) Window around target to start the residency timer x degC early.

// (°C) Temperature proximity considered "close enough" to the target
// Set how far from target the chamber can be and still be considered ok.
#define TEMP_CHAMBER_HYSTERESIS  3

// Temperature Ranges *************************************************
// These parameters help prevent the printer from overheating and catching fire.
// Temperature sensors report abnormally low values when they fail or become disconnected.
// Set these to the lowest value (in degrees C) that the machine is likely to experience.
// Indoor temperatures range from 10C-40C, but a value of 0 might be appropriate for an unheated workshop.
// If any sensor goes below the minimum temperature set here, Marlin will shut down the printer with a “MINTEMP” error.
// Err: MINTEMP: This error means your thermistor has disconnected or become an open circuit. (Or the machine is just very cold.)
// Remember that cold surfaces near hot surfaces can lead to condensation, which is NOT GOOD for electronics.
// Use blower fans to keep air moving and use a Dew Point Calculator to check your local dew point.
#define HEATER_0_MINTEMP 5
#define HEATER_1_MINTEMP 5
#define HEATER_2_MINTEMP 5
#define HEATER_3_MINTEMP 5
#define HEATER_4_MINTEMP 5
#define BED_MINTEMP 5

// Maximum temperature for each temperature sensor.
// If Marlin reads a temperature above these values, it will immediately shut down for safety reasons.
// For the E3D V6 hotend, many use 285 as a maximum value.
// Err: MAXTEMP: This error usually means that the temperature sensor wires are shorted together.
// It may also indicate an issue with the heater MOSFET or relay that is causing it to stay on.
#define HEATER_0_MAXTEMP 285
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define BED_MAXTEMP      130

// PID *************************************************
// Marlin uses PID (Proportional, Integral, Derivative)
// control (Wikipedia) to stabilize the dynamic heating system for the hotends and bed.
// When PID values are set correctly, heaters reach their target temperatures faster,
// maintain temperature better,
// and experience less wear over time.
// Most vitally, correct PID settings will prevent excessive overshoot,
// which is a safety hazard. During PID calibration,
// use the highest target temperature you intend to use (where overshoots are more critical).
// See the PID Tuning topic on the RepRap wiki for detailed instructions on M303 auto-tuning.
// The PID settings should be tuned whenever changing a hotend, temperature sensor, heating element,
// board, power supply voltage (12/24V), or anything else related to the high-voltage circuitry.

// Hotend PID Options
#define PIDTEMP
#define BANG_MAX 255     // limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define K1 0.95 // Disable PIDTEMP to run extruders in bang-bang mode. Bang-bang is a pure binary mode - the heater is either fully-on or fully-off for a long period.
// PID control uses higher frequency PWM and (in most cases) is superior for maintaining a stable temperature.

#if ENABLED(PIDTEMP)
  //#define PID_EDIT_MENU
  //#define PID_AUTOTUNE_MENU
  //#define PID_PARAMS_PER_HOTEND
  //#define PID_DEBUG
  //#define PID_OPENLOOP 1
  //#define SLOW_PWM_HEATERS
  #define PID_FUNCTIONAL_RANGE 10

// Enable PID_AUTOTUNE_MENU to add an option on the LCD to run an Autotune cycle and automatically apply the result.
// Enable PID_PARAMS_PER_HOTEND if you have more than one extruder and they are different models.

// PID Values
  #if ENABLED(PID_PARAMS_PER_HOTEND)
    // Specify between 1 and HOTENDS values per array.
    // If fewer than EXTRUDER values are provided, the last element will be repeated.
    #define DEFAULT_Kp_LIST {  22.20,  22.20 }
    #define DEFAULT_Ki_LIST {   1.08,   1.08 }
    #define DEFAULT_Kd_LIST { 114.00, 114.00 }
  #else
    #define DEFAULT_Kp  22.20
    #define DEFAULT_Ki   1.08
    #define DEFAULT_Kd 114.00
  #endif
// Sample PID values are included for reference, but they won’t apply to most setups.
// The PID values you get from M303 may be very different, but will be better for your specific machine.
// M301 can be used to set Hotend PID and is also accessible through the LCD.
// M304 can be used to set bed PID. M303 should be used to tune PID values before using any new hotend components.

// Bed PID Options *************************************************

//#define PIDTEMPBED
// Enable PIDTEMPBED to use PID for the bed heater (at the same PWM frequency as the extruders).
// With the default PID_dT the PWM frequency is 7.689 Hz,
// fine for driving a square wave into a resistive load without significant impact on FET heating.
// This also works fine on a Fotek SSR-10DA Solid State Relay into a 250 W heater.
// If your configuration is significantly different than this and you don’t understand the issues involved,
// you probably shouldn’t use bed PID until it’s verified that your hardware works. Use M303 E-1 to tune the bed PID for this option.

//#define BED_LIMIT_SWITCHING // Enable BED_LIMIT_SWITCHING

#define MAX_BED_POWER 255
// The max power delivered to the bed. All forms of bed control obey this (PID, bang-bang, bang-bang with hysteresis).
// Setting this to anything other than 255 enables a form of PWM. As with PIDTEMPBED,
// don’t enable this unless your bed hardware is ok with PWM.

// Bed PID Values  
#if ENABLED(PIDTEMPBED)

  //#define PID_BED_DEBUG // Sends debug data to the serial port.
  // 120V 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)
  // from FOPDT model - kp=.39 Tp=405 Tdead=66, Tc set to 79.2, aggressive factor of .15 (vs .1, 1, 10)
  #define  DEFAULT_bedKp 10.00
  #define  DEFAULT_bedKi .023
  #define  DEFAULT_bedKd 305.4

  // 120V 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)
  // from pidautotune
  //#define  DEFAULT_bedKp 97.1
  //#define  DEFAULT_bedKi 1.41
  //#define  DEFAULT_bedKd 1675.16

  // FIND YOUR OWN: "M303 E-1 C8 S90" to run autotune on the bed at 90 degreesC for 8 cycles.
#endif

// PIDTEMPBED *************************************************
// Sample Bed PID values are included for reference, but use the result from M303 E-1 for your specific machine.

// Safety
// Prevent Cold Extrusion 
#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 180
// So-called “cold extrusion” can damage a machine in several ways,
// but it usually just results in gouged filament and a jammed extruder.
// With this option, the extruder motor won’t move if the hotend is below the specified temperature.
// Override this setting with M302 if needed.

// Prevent Lengthy Extrude
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 200
// A lengthy extrusion may not damage your machine,
// but it can be an awful waste of filament.
// This feature is meant to prevent a typo or glitch in a G1 command from extruding some enormous amount of filament.
// For Bowden setups, the max length should be set greater than or equal to the load/eject length.

// Thermal Protection *************************************************
#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed
#define THERMAL_PROTECTION_CHAMBER // Enable thermal protection for the heated chamber
// Thermal protection is one of the most vital safety features in Marlin,
// allowing the firmware to catch a bad situation and shut down heaters before it goes too far.
// Consider what happens when a thermistor comes loose during printing.
// The firmware sees a low temperature reading so it keeps the heat on. As long as the temperature reading is low,
// the hotend will continue to heat up indefinitely, leading to smoke, oozing, a ruined print, and possibly even fire.

// Marlin offers two levels of thermal protection: *************************************************

// Check that the temperature is actually increasing when a heater is on.
// If the temperature fails to rise enough within a certain time period (by default, 2 degrees in 20 seconds),
// the machine will shut down with a “Heating failed” error.
// This will detect a disconnected, loose, or misconfigured thermistor, or a disconnected heater.
// Monitor thermal stability. If the measured temperature drifts too far from the target temperature for too long,
// the machine will shut down with a “Thermal runaway” error.
// This error may indicate poor contact between thermistor and hot end, poor PID tuning, or a cold environment.
// More thermal protection options are located in Configuration_adv.h.
// In most setups these can be left unchanged, but should be tuned as needed to prevent false positives.

// Information
// For false thermal runaways not caused by a loose temperature sensor,
// try increasing WATCH_TEMP_PERIOD or decreasing WATCH_TEMP_INCREASE. Heating may be slowed in a cold environment,
// if a fan is blowing on the heat block, or if the heater has high resistance.

// Kinematics *************************************************
// Marlin supports four kinematic motion systems: Cartesian,
// Core (H-Bot), Delta, and SCARA. Cartesian is the simplest,
// applying each stepper directly to an axis. CoreXY uses a special belt arrangement to do XY motion,
// requiring a little extra maths.
// Delta robots convert the motion of three vertical carriages into XYZ motion in an “effector” attached to the carriages by six arms.
// SCARA robots move an arm in the XY plane using two angular joints.

// CoreXY *************************************************
//#define COREXY
//#define COREXZ
//#define COREYZ
//#define COREYX
//#define COREZX
//#define COREZY
// Enable the option that applies to the specific Core setup. Both normal and reversed options are included for completeness.

// Endstop switch *************************************************
// In open loop systems,
// endstops are an inexpensive way to establish the actual position of the carriage on all axes.
// In the procedure known as “homing,” each axis is moved towards one end until the endstop switch is triggered,
// at which point the machine knows that the axis is at the endstop (home) position. From this point on,
// the machine “knows” its position by keeping track of how far the steppers have been moved.
// If the machine gets out of step for any reason, re-homing may be required.

// Endstop Plugs
// Specify all the endstop connectors that are connected to any endstop or probe.
// Most printers will use all three min plugs. On delta machines, all the max plugs should be used.
// Probes can share the Z min plug, or can use one or more of the extra connectors.
// Don’t enable plugs used for non-endstop and non-probe purposes here.
// SENSORLESS_HOMING will still need endstop connectors declared.
#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG
//#define USE_XMAX_PLUG
//#define USE_YMAX_PLUG
//#define USE_ZMAX_PLUG

// Endstop Pullups
// By default all endstops have pullup resistors enabled.
// This is best for NC switches, preventing the values from “floating.”
// If only some endstops should have pullup resistors, you can disable ENDSTOPPULLUPS and enable pullups individually.
#define ENDSTOPPULLUPS

#if DISABLED(ENDSTOPPULLUPS)
  // Disable ENDSTOPPULLUPS to set pullups individually
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

// Endstop Pulldowns
// By default all endstops have pulldown resistors disabled.
// Endstop Hit State
// Use these options to set to the state (HIGH or LOW) that applies to each endstop and the Z probe, if enabled.

//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // Disable ENDSTOPPULLDOWNS to set pulldowns individually
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

// You can use M119 to test if these are set correctly.
// If an endstop shows up as “TRIGGERED” when not pressed,
// and “open” when pressed, then it should be inverted here.

#define X_MIN_ENDSTOP_HIT_STATE HIGH
#define X_MAX_ENDSTOP_HIT_STATE HIGH
#define Y_MIN_ENDSTOP_HIT_STATE HIGH
#define Y_MAX_ENDSTOP_HIT_STATE HIGH
#define Z_MIN_ENDSTOP_HIT_STATE HIGH
#define Z_MAX_ENDSTOP_HIT_STATE HIGH
#define Z_MIN_PROBE_ENDSTOP_HIT_STATE HIGH

// Stepper Drivers *************************************************
// These settings allow Marlin to tune stepper driver timing and enable advanced options for stepper drivers that support them.
// You may also override timing options in Configuration_adv.h.
#define X_DRIVER_TYPE  A4988
#define Y_DRIVER_TYPE  A4988
#define Z_DRIVER_TYPE  A4988
//#define Z2_DRIVER_TYPE A4988
#define E0_DRIVER_TYPE A4988
//#define E1_DRIVER_TYPE A4988

// Endstop Interrupts
// Enable this feature if all enabled endstop pins are interrupt-capable.
// This will remove the need to poll the interrupt pins, saving many CPU cycles.
//#define ENDSTOP_INTERRUPTS_FEATURE

// Endstop Noise Threshold
// Enable if your probe or endstops falsely trigger due to noise.
//#define ENDSTOP_NOISE_FEATURE

// Movement *************************************************
// Enable DISTINCT_E_FACTORS if your extruders are not all mechanically identical.
// With this setting you can optionally specify different steps-per-mm, max feedrate, and max acceleration for each extruder.
// Distinct E Factors

//#define DISTINCT_E_FACTORS
// These are the most crucial settings for your printer,
// as they determine how accurately the steppers will position the axes.
// Here we’re telling the firmware how many individual steps produce a single millimeter (or degree on SCARA) of movement.
// These depend on various factors, including belt pitch, number of teeth on the pulley,
// thread pitch on leadscrews, micro-stepping settings, and extruder style.
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 4000, 500 }// Default Steps per mm

// Override with M92.
// Step Calculator
// The Průša Calculator is a great tool to help find the right values for your specific printer configuration.

// Default Max Feed Rate
// In any move, the velocities (in mm/sec) in the X, Y, Z, and E directions,
// will be limited to the corresponding DEFAULT_MAX_FEEDRATE.
#define DEFAULT_MAX_FEEDRATE { 500, 500, 2.25, 45 }

// Override with M203.
// Setting these too high will cause the corresponding stepper motor to lose steps, especially on high speed movements.

// Acceleration
// Default Max Acceleration
// When the velocity of any axis changes,
// its acceleration (or deceleration) in mm/s/s is limited by the current max acceleration setting.
// Also see the jerk settings below, which specify the largest instant speed change that can occur between segments.
// A value of 3000 means that an axis may accelerate by 100mm/s within 1/30th of a second,
// or up to 3000mm/s (180000mm/m) in a full second.
// Jerk sets the floor for accelerated moves.
// If the change in top speed for a given axis between segments is less than the jerk value for the axis,
// an instantaneous change in speed may be allowed. Limits placed on other axes also apply.
// Basically, lower jerk values result in more accelerated moves, which may be near-instantaneous in some cases,
// depending on the final acceleration determined by the planner.
// Override with M201.
#define DEFAULT_MAX_ACCELERATION      { 3000, 3000, 100, 10000 }

// Default Acceleration *************************************************
// The planner uses the default accelerations set here (or by M204) as the starting values for movement acceleration,
// and then constrains them further, if needed.
// There are separate default acceleration values for printing moves, retraction moves, and travel moves.
// Printing moves include E plus at least one of the XYZ axes.
// Retraction moves include only the E axis.
// Travel moves include only the XYZ axes.
// In print/travel moves, DEFAULT_ACCELERATION and DEFAULT_TRAVEL_ACCELERATION apply to the XYZ axes.
// In retraction moves, DEFAULT_RETRACT_ACCELERATION applies only to the E-axis. During movement planning,
// Marlin constrains the default accelerations to the maximum acceleration of all axes involved in the move.
// Override with M204.
// Don’t set these too high. Larger acceleration values can lead to excessive vibration, noisy steppers,
// or even skipped steps. Lower acceleration produces smoother motion, eliminates vibration,
// and helps reduce wear on mechanical parts.
#define DEFAULT_ACCELERATION          3000    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  3000    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   3000    // X, Y, Z acceleration for travel (non printing) moves

// Jerk  *************************************************
#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3
  //#define TRAVEL_EXTRA_XYJERK 0.0     // Additional jerk allowance for all travel moves
  //#define LIMITED_JERK_EDITING        // Limit edit via M205 or LCD to DEFAULT_aJERK * 2
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits
  #endif
#endif

#define DEFAULT_EJERK    5.0  // May be used by Linear Advance
// Configuration Update
// Junction Deviation is now the default mode. Enabling CLASSIC JERK will override it.
// Jerk works in conjunction with acceleration (see above). Jerk is the maximum change in velocity (in mm/sec) that can occur instantaneously. It can also be thought of as the minimum change in velocity that will be done as an accelerated (not instantaneous) move.
// Both acceleration and jerk affect your print quality. If jerk is too low, the extruder will linger too long on small segments and corners, possibly leaving blobs. If the jerk is set too high, direction changes will apply too much torque and you may see “ringing” artifacts or dropped steps.
// Override with M205.
// Junction Deviation  
#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.013 // (mm) Distance from real junction edge
#endif

// Junction Deviation determins the cornering speed. The smaller the value the slower the cornering speed will be.
// Junction Deviation formula
// Use the above formula to calculate the Junction Deviation amount.
// See the following sources for detailed explanations of Junction Deviation:
// JD Explained and Visualized, by Paul Wanamaker
// Computing JD for Marlin Firmware
// Improving GRBL: Cornering Algorithm

// S-Curve Acceleration  *************************************************
// This option eliminates vibration during printing by fitting a Bézier curve to move acceleration,
// producing much smoother direction changes.
//#define S_CURVE_ACCELERATION

// Z Probe Options *************************************************

// Use this option in all cases when the probe is connected to the Z MIN endstop plug.
// This option is used for DELTA robots, which always home to MAX, and may be used in other setups.
// You can use this option to configure a machine with no Z endstops.
// In that case the probe will be used to home Z and you will need to enable Z_SAFE_HOMING
// to ensure that the probe is positioned over the bed when homing the Z axis - done after X and Y.
// Probe Pins

// With Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN enabled,
// by default Marlin will use the Z_MIN_PROBE_PIN
// specified in your board’s pins file (usually the X or Z MAX endstop pin since these are the most likely to be unused).
// If you need to use a different pin, define it here in Configuration.h.
// Probe Type Marlin supports any kind of probe that can be made to work like a switch. Specific types of probes have different needs.
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
//#define Z_MIN_PROBE_PIN 32

// Manual Probe (no probe)
// Even if you have no bed probe you can still use any of the core AUTO_BED_LEVELING_*
// options below by selecting this option.
// With PROBE_MANUALLY the G29 command only moves the nozzle to the next probe point where it pauses.
// You adjust the Z height with a piece of paper or feeler gauge,
// then send G29 again to continue to the next point.
// You can also enable LCD_BED_LEVELING to add a “Level Bed” Menu item to the LCD for a fully interactive leveling process.
// MANUAL_PROBE_START_Z sets the Z-height the printer initially moves to at each mesh point during manual probing.
// With this disabled, the printer will move to Z0 for the first probe point.
// Then each consecutive probe point uses the Z position of the probe point preceding it.
//#define PROBE_MANUALLY
  //#define MANUAL_PROBE_START_Z 0.2

// Fix Mounted Probe
// Fixed Probe - EZABL

//#define FIX_MOUNTED_PROBE
// This option is for any probe that’s fixed in place, with no need to be deployed or stowed.
// Specify this type for an inductive probe or when using the nozzle itself as the probe.

// Servo Z Probe
// To indicate a Servo Z Probe (e.g., an endstop switch mounted on a rotating arm) just specify the servo index.
// Use the M280 command to find the best Z_SERVO_ANGLES values.

//#define Z_PROBE_SERVO_NR 0       // Defaults to SERVO 0 connector.
//#define Z_SERVO_ANGLES { 70, 0 } // Z Servo Deploy and Stow angles

// BLTouch
// The ANTCLABS BLTouch probe uses custom circuitry and a magnet to raise and lower a metal pin which acts as a touch probe.
// The BLTouch uses the servo connector and is controlled using specific servo angles.
// With this option enabled the other required settings are automatically configured
// (so there’s no need to enter servo angles, for example).
//#define BLTOUCH

// TOUCH MI PROBE
// Touch-MI Probe by hotends.fr is deployed and activated by moving the X-axis to a magnet at the edge of the bed. By default,
// the magnet is assumed to be on the left and activated by a home.
// If the magnet is on the right, enable and set TOUCH_MI_DEPLOY_XPOS
// to the deploy position. Also option requires: BABYSTEPPING, BABYSTEP_ZPROBE_OFFSET, Z_SAFE_HOMING, 
// and a minimum Z_HOMING_HEIGHT of 10.
//#define TOUCH_MI_PROBE
#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 0.5                  // Height at which the probe retracts
  //#define TOUCH_MI_DEPLOY_XPOS (X_MAX_BED + 2)  // For a magnet on the right side of the bed
  //#define TOUCH_MI_MANUAL_DEPLOY                // For manual deploy (LCD menu)
#endif

// Solenoid probe
// A probe that is deployed and stowed with a solenoid pin (Defined as SOL1_PIN.)
//#define SOLENOID_PROBE

// Z-Probe Sled
// This type of probe is mounted on a detachable “sled” that sits at the far end of the X axis.
// Before probing, the X carriage moves to the far end and picks up the sled.
// When probing is completed, it drops the sled off. The SLED_DOCKING_OFFSET
// specifies the extra distance the X axis must travel to pickup the sled.
// 0 should be fine but it may be pushed further if needed.
//#define Z_PROBE_SLED
//#define SLED_DOCKING_OFFSET 5


// Rack-and-pinion probe
// A probe deployed by moving the X-axis (e.g., Wilson II’s rack-and-pinion probe designed by Marty Rice.)
//#define RACK_AND_PINION_PROBE
  #if ENABLED(RACK_AND_PINION_PROBE)
    #define Z_PROBE_DEPLOY_X  X_MIN_POS
    #define Z_PROBE_RETRACT_X X_MAX_POS
  #endif
#endif

// Allen Key
// A retractable Z-probe for deltas that uses an Allen key as the probe.
// See “Kossel automatic bed leveling probe” at the RepRap wiki.
// It deploys by leveraging against the Z-axis belt, and retracts by pushing the probe down.
// More information will be included in an upcoming Delta configuration page.
//#define Z_PROBE_ALLEN_KEY

// Probe Offsets  cc 0,0 (extruder)
// These offsets specify the distance from the tip of the nozzle to the probe — or more precisely,
// to the point at which the probe triggers.
// The X and Y offsets are specified as integers.
// The Z offset should be specified as exactly as possible using a decimal value.
// The Z offset can be overridden with M851 Z or the LCD controller. The M851 offset is saved to EEPROM with M500.
// Distance from edge
#define X_PROBE_OFFSET_FROM_EXTRUDER 10  // X offset: -left  +right  [of the nozzle]
#define Y_PROBE_OFFSET_FROM_EXTRUDER 10  // Y offset: -front +behind [the nozzle]
#define Z_PROBE_OFFSET_FROM_EXTRUDER 0   // Z offset: -below +above  [the nozzle]

#define PROBING_MARGIN 10
// Certain types of probe need to stay away from the edge

// Probing Speed
// X and Y axis travel speed (mm/m) between probes
#define XY_PROBE_SPEED 8000

// Feedrate (mm/m) for the first approach when double-probing (MULTIPLE_PROBING == 2)
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z

// Feedrate (mm/m) for the "accurate" probe of each point
#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)
// Probing should be done quickly, but the Z speed should be tuned for best repeatability. Depending on the probe, a slower Z probing speed may be needed for repeatable results.

// Multiple Probes
// Probing multiple times yields better results. Set to 2 for a fast/slow probe - the second probe result will be used.
// Set to 3 or more for slow probes - the average result will be used.
//#define MULTIPLE_PROBING 2
//#define EXTRA_PROBING    1

// Probe Clearance
// Z probes require clearance when deploying, stowing, and moving between probe points to avoid hitting the bed and other hardware.
// Servo-mounted probes require extra space for the arm to rotate. Inductive probes need space to keep from triggering early.
// Use these settings to specify the distance (mm) to raise the probe (or lower the bed).
// The values set here apply over and above any (negative) probe Z Offset set with Z_PROBE_OFFSET_FROM_EXTRUDER,
// M851, or the LCD. Only integer values >= 1 are valid for these settings.
// Example: M851 Z-5 with a CLEARANCE of 4 => 9 mm from bed to nozzle.
// But: M851 Z+1 with a CLEARANCE of 2 => 2 mm from bed to nozzle.
// G29 Movement
// Make sure you have enough clearance for the probe to move between points!
#define Z_CLEARANCE_DEPLOY_PROBE   10 // Z Clearance for Deploy/Stow
#define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Clearance between probe points
#define Z_CLEARANCE_MULTI_PROBE     5 // Z Clearance between multiple probes
//#define Z_AFTER_PROBING           5 // Z position after probing is done
#define Z_PROBE_LOW_POINT          -2 // Farthest distance below the trigger-point to go before stopping

// For M851 and LCD menus give a range for adjusting the Z probe offset.
#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20


// Probe Testing
// This enables you to test the reliability of your probe.
// Issue a M48 command to start testing. It will give you a standard deviation for the probe.
// Tip: 0.02mm is normally acceptable for bed leveling to work.
#define Z_MIN_PROBE_REPEATABILITY_TEST

// Before deploy/stow pause for user confirmation
//#define PAUSE_BEFORE_DEPLOY_STOW
#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
  //#define PAUSE_PROBE_DEPLOY_WHEN_TRIGGERED // For Manual Deploy Allenkey Probe
#endif
// Before deploy/stow pause for user confirmation

// Probe with heaters off
// Heatinging the bed and extruder for probing will produce results that more accurately correspond
// with your bed if you typically print with the bed heated. Enable PROBING_HEATERS_OFF if you
// are experiencing electrical noise. A delay can also be added to allow noise and vibration to settle.
//#define PROBING_HEATERS_OFF       // Turn heaters off when probing
#if ENABLED(PROBING_HEATERS_OFF)
  //#define WAIT_FOR_BED_HEATER     // Wait for bed to heat back up between probes (to improve accuracy)
#endif
//#define PROBING_FANS_OFF          // Turn fans off when probing
//#define PROBING_STEPPERS_OFF      // Turn steppers off (unless needed to hold position) when probing
//#define DELAY_BEFORE_PROBING 200  // (ms) To prevent vibrations from triggering piezo sensors

// Stepper Spin - Stepper Drivers
// These options set the pin states used for stepper enable.
// The most common setting is 0 (LOW) for Active Low. For Active High use 1 or HIGH.

// Motor Enable *************************************************
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

// Use these options to disable steppers when not being issued a movement.
// This was implemented as a hack to run steppers at higher-than-normal current
// in an effort to produce more torque at the cost of increased heat for drivers and steppers.
// Disabling the steppers between moves gives the motors and drivers a chance to cool off.
// It sounds good in theory, but in practice it has drawbacks.
// Disabled steppers can’t hold the carriage stable.
// This results in poor accuracy and carries a strong probability of axial drift (i.e., lost steps).
// Most 3D printers use an “open loop” control system,
// meaning the software can’t ascertain the actual carriage position at a given time.
// It simply sends commands and assumes they have been obeyed.
// In practice with a well-calibrated machine this is not an issue and using open loop is a major cost saving with excellent quality.

// We don’t recommend this hack.
// There are much better ways to address the problem of stepper/driver overheating.
// Some examples: stepper/driver heatsink, active cooling, dual motors on the axis,
// reduce micro-stepping, check belt for over tension, check components for smooth motion, etc.

// Motor Disable
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

//#define DISABLE_REDUCED_ACCURACY_WARNING // Enable this option to suppress the warning given in cases when reduced accuracy is likely to occur.

// The E disable option works like DISABLE_[XYZ] but pertains to one or more extruders.
// The default setting keeps the active extruder enabled, disabling all inactive extruders.
// This is reasonable for situations where a “wipe tower” or other means is used to ensure
// that the nozzle is primed and not oozing between uses.
#define DISABLE_E false 					        // For all extruders
#define DISABLE_INACTIVE_EXTRUDER	false 	// Keep only the active extruder enabled

// Motor Direction
// These settings reverse the motor direction for each axis.
// Be careful when first setting these. Axes moving the wrong direction can cause damage.
// Get these right without belts attached first, if possible.
// Before testing, move the carriage and bed to the middle.
// Test each axis for proper movement using the host or LCD “Move Axis” menu.
// If an axis is inverted, either flip the plug around or change its invert setting.
#define INVERT_X_DIR false
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false

#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false


// Homing and Bounds *************************************************
// Z Homing Height // Home Icon

//#define NO_MOTION_BEFORE_HOMING	// Inhibit movement until all axes have been homed
//#define UNKNOWN_Z_NO_RAISE    // Don't raise Z (lower the bed) if Z is "unknown."
								              	//For beds that fall when Z is powered off.
//#define Z_HOMING_HEIGHT 4

// This value raises Z to the specified height above the bed before homing X or Y.
// This is useful to prevent the head crashing into bed mountings such as screws,
// bulldog clips, etc. This also works with auto bed leveling enabled and will be triggered
// only when the Z axis height is less than the defined value, otherwise the Z axis will not move.
// NO_MOTION_BEFORE_HOMING and UNKNOWN_Z_NO_RAISE
// Homing direction for each axis: -1 = min, 1 = max. Most Cartesian and core machines have three min endstops.
// Deltas have three max endstops. For other configurations set these values appropriately.
// Homing Direction
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

// With Marlin you can directly specify the bed size.
// This allows Marlin to do extra logic related to the bed size when it differs from the movement limits below.
// If the XY carriage is able to move outside of the bed, you can specify a wider range below.
// Movement Bounds
#define X_BED_SIZE 200
#define Y_BED_SIZE 200

// These values specify the physical limits of the machine.
// Usually the [XYZ]_MIN_POS values are set to 0, because endstops are positioned at the bed limits.
// [XYZ]_MAX_POS should be set to the farthest reachable point. By default,
// these are used as your homing positions as well. However,
// the MANUAL_[XYZ]_HOME_POS options can be used to override these, if needed.
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 170


// Home Offset *************************************************
// Although home positions are fixed, M206 can be used to apply offsets to the home position if needed.
// Software Endstops
//#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif

// Enable these options to constrain movement to the physical boundaries of the machine
// (as set by [XYZ]_(MIN|MAX)_POS). For example, G1 Z-100 can be min constrained to G1 Z0.
// It is recommended to enable these options as a safety feature. If software endstops need to be disabled, use M211 S0.
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

// Enable/Disable software endstops from the LCD
#if defined(MIN_SOFTWARE_ENDSTOPS) || defined(MAX_SOFTWARE_ENDSTOPS)
  #define SOFT_ENDSTOPS_MENU_ITEM
#endif


// Filament Runout Sensor *************************************************

//#define FILAMENT_RUNOUT_SENSOR
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define NUM_RUNOUT_SENSORS   1     // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.
  #define FIL_RUNOUT_INVERTING false // Set to true to invert the logic of the sensor.
  #define FIL_RUNOUT_PULLUP          // Use internal pullup for filament runout pins.
  //#define FIL_RUNOUT_PULLDOWN      // Use internal pulldown for filament runout pins.

  // Set one or more commands to execute on filament runout.
  // (After 'M412 H' Marlin will ask the host to handle the process.)
  #define FILAMENT_RUNOUT_SCRIPT "M600"
  
//#define FILAMENT_RUNOUT_DISTANCE_MM 25
  // When using a runout switch (no encoder), after a runout is detected,
  // continue printing this length of filament before executing the runout script.
  // Useful for a sensor at the end of a feed tube.
  // If using an encoder disc, this is the length of filament that would print
  // without any movement from the sensor before it triggers a runout.
  // Requires 4 bytes SRAM per sensor, plus 4 bytes overhead.
  
    // Enable this option to use an encoder disc that toggles the runout pin as the filament moves.
    // Be sure to set FILAMENT_RUNOUT_DISTANCE_MM large enough to avoid false positives.
    // Start at the value of the sensor for one revolution and if you experience false positives,
    // increment the value by the same amount.
    // ie., 7mm is set, and you get false positives, set it to 14 and try it again.
  
  // RAMPS-based boards use SERVO3_PIN. For other boards you may need to define FIL_RUNOUT_PIN.
  // Enable the M43 feature in your firmware (PINS_DEBUGGING) and load it to your printer.
  // Assuming you already have a runout sensor (switch based) there,
  // you can watch the pin states while toggling the runout sensor on an off to see which pin is changing.
  // With this feature, a mechanical or opto endstop switch is used to check for the presence of
  // filament in the feeder (usually the switch is closed when filament is present).
  // If the filament runs out, Marlin will run the specified G-code script (by default M600).
  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
    //#define FILAMENT_MOTION_SENSOR
  #endif
#endif

// Bed Leveling *************************************************

// Bed Level
// Bed Leveling is a standard feature on many 3D printers.
// It takes the guess-work out of getting a good first layer and good bed adhesion.
// It is highly recommended to get your printer aligned and constrained as much as possible before using bed leveling,
// because it exists to compensate for imperfections in the hardware.
// For all the in-depth details please read the Auto Bed Leveling documentation and the G29 G-codes documentation.

// With Bed Leveling enabled:
// By default G28 disables bed leveling. Follow G28 with M420 S to turn leveling on.
// With ENABLE_LEVELING_AFTER_G28 leveling will always be enabled after G28.
// With RESTORE_LEVELING_AFTER_G28 leveling is restored to whatever state it was in before G28.
// G29 will automatically probe the bed or guide you to do a paper-test at various points. After measurement it calculates a correction grid or matrix and enables leveling compensation. The specific behavior depends on configuration and type of bed leveling.
// M500 will save the bed leveling data to EEPROM. M501 will load it. M502 will erase it. And M503 will report it.
// M420 S<bool> can be used to enable/disable bed leveling. For example, M420 S1 must be used after M501 to enable the loaded mesh or matrix, and to re-enable leveling after G28, which disables leveling compensation.
// A “Level Bed” menu item can be added to the LCD with the LCD_BED_LEVELING option.
//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
//#define AUTO_BED_LEVELING_BILINEAR
//#define AUTO_BED_LEVELING_UBL
//#define MESH_BED_LEVELING

// Enable just one type of Bed Leveling.
// AUTO_BED_LEVELING_3POINT probes three points in a triangle. The flat plane gives a transform matrix suitable to compensate for a flat but tilted bed.
// AUTO_BED_LEVELING_LINEAR probes the bed in a grid. A transform matrix is produced by least-squares method to compensate for a flat but tilted bed.
// AUTO_BED_LEVELING_BILINEAR probes the bed in a grid, with optional Catmull-Rom subdivision. The mesh data is used to adjust Z height across the bed using bilinear interpolation. Good for delta, large, or uneven beds.
// AUTO_BED_LEVELING_UBL (recommended) combines the features of 3-point, linear, bilinear, and mesh leveling. As with bilinear leveling, the mesh data generated by UBL is used to adjust Z height across the bed using bilinear interpolation. An LCD controller is currently required.
// MESH_BED_LEVELING provides a custom G29 command to measure the bed height at several grid points using a piece of paper or feeler gauge. See G29 for MBL for the full procedure. This type of leveling is only compatible with PROBE_MANUALLY.
// Only AUTO_BED_LEVELING_BILINEAR and AUTO_BED_LEVELING_UBL support DELTA.
// Only AUTO_BED_LEVELING_BILINEAR currently supports SCARA.
// MESH_BED_LEVELING is incompatible with Delta and SCARA.

// Restore after G28
// Normally G28 causes leveling to be disabled,
// so you have to re-enable it with M420 S1 or G29.
// If you enable this option then G28 will make sure to turn leveling back on if it was enabled beforehand.
//#define RESTORE_LEVELING_AFTER_G28

// Debug Leveling
// Use this option to enable extra debugging of homing and leveling.
// You can then use M111 S32 before issuing G28 and G29 V4 to get a detailed log of the process for diagnosis.
// This option is useful to figure out the cause of unexpected behaviors, or when reporting issues to the project.
//#define DEBUG_LEVELING_FEATURE

// Leveling Fade Height
// #define ENABLE_LEVELING_FADE_HEIGHT // Available with MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, and AUTO_BED_LEVELING_UBL.

// This option adds the Z parameter to M420 which sets a fade distance over which leveling will be gradually reduced.
// Above the given Z height, leveling compensation will no longer be applied.
// This feature exists to prevent irregularities in the bed from propagating through the model’s entire height.
// Fading out leveling also reduces computational requirements and resonance from the Z axis above the fade height.
// For a well-aligned machine, this feature can improve print results.

// Example: To have leveling fade out over the first 10mm of layer printing use M420 Z10.
// If each layer is 0.2 mm high, leveling compensation will be reduced by 1/50th (2 %) after each layer.
// Above 10mm the machine will move without compensation.

// G26 Mesh Validation Pattern
/**
 * Enable the G26 Mesh Validation Pattern tool.
 // When using any of the mesh-based leveling systems (1.1.7) you can activate G26_MESH_VALIDATION
 // to print test patterns and fine-tune the mesh. See G26 Mesh Validation for full details.
 // The G26 command accepts parameters for nozzle size, layer height, etc. The sub-options above
 // specify the default values that will be applied for omitted parameters.
 */
#define G26_MESH_VALIDATION   // Enable G26 mesh validation
#if ENABLED(G26_MESH_VALIDATION)
  #define MESH_TEST_NOZZLE_SIZE     0.4   // (mm) Diameter of primary nozzle.
  #define MESH_TEST_LAYER_HEIGHT    0.2   // (mm) Default layer height for the G26 Mesh Validation Tool.
  #define MESH_TEST_HOTEND_TEMP   205   // (°C) Default nozzle temperature for the G26 Mesh Validation Tool.
  #define MESH_TEST_BED_TEMP       60   // (°C) Default bed temperature for the G26 Mesh Validation Tool.
  #define G26_XY_FEEDRATE         20    // (mm/s) Feedrate for XY Moves for the G26 Mesh Validation Tool.

#endif

// These options specify the default number of points to probe in each dimension during G29.
// Linear / Bilinear Options
#define GRID_MAX_POINTS_X 3
#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

// These settings specify the boundaries for probing with G29.
// This will most likely be a sub-section of the bed because probes are not usually able to reach every point that the nozzle can.
// Take account of the probe’s XY offsets when setting these boundaries.
//#define PROBING_MARGIN_LEFT PROBING_MARGIN
//#define PROBING_MARGIN_RIGHT PROBING_MARGIN
//#define PROBING_MARGIN_FRONT PROBING_MARGIN
//#define PROBING_MARGIN_BACK PROBING_MARGIN

//#define PROBE_Y_FIRST // Enable this option if probing should proceed in the Y dimension first instead of X first.

// Bilinear Options
// Usually the probed grid doesn’t extend all the way to the edges of the bed.
// So, outside the bounds of the probed grid, Z adjustment can take one of two approaches.
// Either the Z height can continue to raise/lower by the established tilt of the nearest grid box
// (best when most of the bed was probed), or it can follow the contour of the nearest edge (the default).
// Enable this option for extrapolation.
//#define EXTRAPOLATE_BEYOND_GRID

// If you have SRAM to spare, this option will multiply the resolution of the bilinear grid using the Catmull-Rom subdivision method.
// This option only applies to bilinear leveling. If the default value of 3 is too expensive, try 2 or 1.
// (In Marlin 1.1.1, the default grid will be stored in PROGMEM, as UBL now does.)
//#define ABL_BILINEAR_SUBDIVISION
#if ENABLED(ABL_BILINEAR_SUBDIVISION)
  // Number of subdivisions between probe points
  #define BILINEAR_SUBDIVISIONS 3
#endif


// Unified Bed Leveling Options // Probe Points
// These options specify the inset, grid, and 3-point triangle to use for UBL.
// Note that probe XY offsets and movement limits may constrain the probeable area of the bed.
#define UBL_MESH_INSET 1          // Mesh inset margin on print area
#define GRID_MAX_POINTS_X 10      // Don't use more than 15 points per axis, implementation limited.
#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  #define UBL_MESH_EDIT_MOVES_Z     // Sophisticated users prefer no movement of nozzle
  #define UBL_SAVE_ACTIVE_ON_M500   // Save the currently active mesh in the current slot on M500
  //#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 // When the nozzle is off the mesh, this value is used
                                          // as the Z-Height correction value.

// Mesh Bed Leveling Options
#define MESH_INSET 10          // Mesh inset margin on print area
#define GRID_MAX_POINTS_X 3    // Don't use more than 7 points per axis, implementation limited.
#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

//#define MESH_G28_REST_ORIGIN // After homing all axes ('G28' or 'G28 XYZ') rest Z at Z_MIN_POS
// These options specify the number of points that will always be probed in each dimension during G29.
// The mesh inset is used to automatically calculate the probe boundaries.
// These can be set explicitly in Configuration_adv.h.
// MESH_G28_REST_ORIGIN moves the nozzle to rest at Z_MIN_POS when mesh probing is done.
// If Z is offset (e.g., due to home_offset or some other cause) this is intended to move Z to a good starting point, usually Z=0.

// LCD Bed Leveling
// Available with MESH_BED_LEVELING and PROBE_MANUALLY (all forms of Auto Bed Leveling).
// See the Configuration.h file for sub-options and the G29 G-code documentation that applies to your selected leveling system.
//#define LCD_BED_LEVELING
#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 // (mm) Step size while manually probing Z axis.
  #define LCD_PROBE_Z_RANGE 4     // (mm) Z Range centered on Z_MIN_POS for LCD Z adjustment
  //#define MESH_EDIT_MENU        // Add a menu to edit mesh points
#endif
// LCD_BED_LEVELING adds a “Level Bed” menu to the LCD that starts a step-by-step guided leveling procedure that requires no probe.

// Corner Leveling
//#define LEVEL_BED_CORNERS
#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET 30    // (mm) An inset for corner leveling
  #define LEVEL_CORNERS_Z_HOP  4.0  // (mm) Move nozzle up before moving between corners
  #define LEVEL_CORNERS_HEIGHT 0.0  // (mm) Z height of nozzle at leveling points
  //#define LEVEL_CENTER_TOO        // Move to the center after the last corner
#endif
// Add a menu item to move between bed corners for manual bed adjustment.

// Z Probe End Script
//#define Z_PROBE_END_SCRIPT "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"
// A custom script to do at the very end of G29. If multiple commands are needed, divide them with \n (the newline character).

// Homing Options ********************************************
// Bed Center at 0,0
//#define BED_CENTER_AT_0_0
// Enable this option if the bed center is at X0 Y0. This setting affects the way automatic home positions (those not set with MANUAL_[XYZ]_POS) are calculated. This should always be enabled with DELTA.

// Manual Home Position
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0 // Distance from nozzle to printbed after homing
// These settings are used to override the home position. Leave them undefined for automatic settings. For DELTA Z home must be set to the top-most position.

// Z Safe Homing
#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT ((X_BED_SIZE) / 2)    // X point for Z homing when homing all axes (G28).
  #define Z_SAFE_HOMING_Y_POINT ((Y_BED_SIZE) / 2)    // Y point for Z homing when homing all axes (G28).
#endif
// Z Safe Homing prevents Z from homing when the probe (or nozzle) is outside bed area by moving to a defined XY point
// (by default, the middle of the bed) before Z Homing when homing all axes with G28.
// As a side-effect, X and Y homing are required before Z homing. If stepper drivers time out,
// X and Y homing will be required again.

// Enable this option if a probe (not an endstop) is being used for Z homing.
// Z Safe Homing isn’t needed if a Z endstop is used for homing,
// but it may also be enabled just to have XY always move to some custom position after homing.

// Homing Speed
// Homing speeds (mm/m)
#define HOMING_FEEDRATE_XY (50*60)
#define HOMING_FEEDRATE_Z  (4*60)
// Homing speed for use in auto home and auto bed leveling.
// These values may be set to the fastest speeds your machine can achieve.
// Homing and probing speeds are constrained by the current max feedrate and max acceleration settings.

// Setting these values too high may result in reduced accuracy and/or skipped steps.
// Reducing acceleration may help to achieve higher top speeds.

#define VALIDATE_HOMING_ENDSTOPS
// Validate that endstops are triggered on homing moves.

// Bed Skew Compensation  ********************************************
// Correct for misalignment in the XYZ axes. See Configuration.h for a thorough explanation.
//#define SKEW_CORRECTION
#if ENABLED(SKEW_CORRECTION)
  // Input all length measurements here:
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  // Or, set the default skew factors directly here
  // to override the above measurements:
  #define XY_SKEW_FACTOR 0.0

  //#define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200
    #define XZ_SKEW_FACTOR 0.0
    #define YZ_SKEW_FACTOR 0.0
  #endif

  // Enable this option for M852 to set skew at runtime
  //#define SKEW_CORRECTION_GCODE
#endif


// ******************************************** Additional Features ********************************************
// EEPROM
// Commands like M92 only change the settings in volatile memory,
// and these settings are lost when the machine is powered off.
// With this option enabled, Marlin uses the built-in EEPROM to preserve settings across reboots.
// Settings saved to EEPROM (with M500) are loaded automatically whenever the machine restarts
// (and in most setups, when connecting to a host), overriding the defaults set in the configuration files.
// This option is highly recommended, as it makes configurations easier to manage.
//#define EEPROM_SETTINGS

// The EEPROM-related commands are:
// M500: Save all current settings to EEPROM.
// M501: Load all settings last saved to EEPROM.
// M502: Reset all settings to their default values (as set by Configuration.h)
// M503: Print the current settings (in RAM, not EEPROM)
// These EEPROM options should be left as they are,
// but for 128K and smaller boards they may be used to recover some program memory.
// Vendors are strongly discouraged from using DISABLE_M503.

// EEPROM Options
// Settings that can be changed and saved to EEPROM are marked with .
// Options marked with  can be changed from the LCD controller.
// When you change saveable settings in the configuration files and re-flash,
// the new values don’t take effect right away. They are still overridden by the saved values in EEPROM.
// To get your new default settings into the EEPROM, use M502 followed by M500.
//#define DISABLE_M503    // Saves ~2700 bytes of PROGMEM. Disable for release!
// #define EEPROM_CHITCHAT   // Give feedback on EEPROM commands. Disable to save PROGMEM.

// Host Keepalive
// When Host Keepalive is enabled Marlin will send a busy status message to the host every couple
// of seconds when it can’t accept commands. Disable if your host doesn’t like keepalive messages.
// Use DEFAULT_KEEPALIVE_INTERVAL for the default number of seconds between “busy” messages.
// Override with M113. Marlin 1.1.5 and up include the BUSY_WHILE_HEATING option for hosts that
// treat host keepalive as a strict busy protocol.
// #define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
// #define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
// #define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating

// Free Memory Watcher
//#define M100_FREE_MEMORY_WATCHER // Uncomment to add the M100 Free Memory Watcher for debugging purposes.

// Inch Units
//#define INCH_MODE_SUPPORT // This option adds support for the G20 and G21 commands, allowing G-code to specify units in inches.

// Temperature Units
// This option adds support for M149 C, M149 K, and M149 F to set temperature units to Celsius, Kelvin,
// or Fahrenheit. Without this option all temperatures must be specified in Celsius units.
//#define TEMPERATURE_UNITS_SUPPORT

// LCD Material Presets  
// These are the default values for the Prepare > Preheat LCD menu options.
// These values can be overridden using the M145 command or the Control > Temperature > Preheat Material X conf submenus.
#define PREHEAT_1_TEMP_HOTEND 180
#define PREHEAT_1_TEMP_BED     70
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

// Park the nozzle at the given XYZ position on idle or G27.
// The “P” parameter controls the action applied to the Z axis:

// P0 - (Default) If Z is below park Z raise the nozzle.
// P1 - Raise the nozzle always to Z-park height.
// P2 - Raise the nozzle by Z-park amount, limited to Z_MAX_POS.
// Nozzle Clean
// Adds the G12 command to perform a nozzle cleaning process. See Configuration.h for additional configuration options.
//#define NOZZLE_CLEAN_FEATURE
#if ENABLED(NOZZLE_CLEAN_FEATURE)
  #define NOZZLE_CLEAN_STROKES  12  // Default number of pattern repetitions
  #define NOZZLE_CLEAN_TRIANGLES  3 // Default number of triangles
  #define NOZZLE_CLEAN_START_POINT { 30, 30, (Z_MIN_POS + 1)} // Specify positions as { X, Y, Z }
  #define NOZZLE_CLEAN_END_POINT   { 100, 60, (Z_MIN_POS + 1) }
  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5 // Circular pattern radius
  #define NOZZLE_CLEAN_CIRCLE_FN 10      // Circular pattern circle fragments number
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT // Middle point of circle
  #define NOZZLE_CLEAN_GOBACK // Move the nozzle to the initial position after cleaning
  //#define NOZZLE_CLEAN_NO_Z // Enable for a purge/clean station that's always at the gantry height (thus no Z move)
#endif

// Print Job Timer ********************************************
// Automatically start and stop the print job timer when M104/M109/M190 commands are received.
// Also adds the following commands to control the timer:
// M75 - Start the print job timer.
// M76 - Pause the print job timer.
// M77 - Stop the print job timer.
// Total print jobs
// Total successful print jobs
// Total failed print jobs
// Total time printing
// This information can be viewed by the M78 command.
#define PRINTJOB_TIMER_AUTOSTART
  //#define PRINTCOUNTER // When enabled Marlin will keep track of some print statistics such as:

// User Interface Language ********************************************
// Choose your preferred language for the LCD controller here. Supported languages include:
// Code	Language // See language.h for the latest list of supported languages and their international language codes.
//Code	Language
//an Aragonese  bg  Bulgarian
//ca Catalan    cz  Czech
//da Danish     de  German
//es Spanish	  eu  Basque-Euskera
//en English (Default)     fr_na	  French (no accent)
//el  Greek                   fi Finnish
//el_gr Greek (Greece)     el_CY Greek (Cyprus)
//fr  French 	                gl Galician
//hr  Croatian(Hrvatski)      hu Hungarian / Magyar
//it Italian               ko_KR	Korean
//nl Dutch	 	                pl  Polish
//jp_kana  Japanese(Kana)  pt_br Portuguese(Brazil)
//pt  Portug                  ro  Romanian
//ru  Russian                 sk  Slovak
//sv  Swedish                 tr  Turkish
//uk Ukrainian                vi  Vietnamese
//zh_CN	Simplified Chinese  zh_TW Traditional Chinese
//test test your LCD screen
// See LCD Language System for in-depth info on how the Marlin display system currently works.
// To determine the language extension installed on your controller:
// Compile and upload with LCD_LANGUAGE set to ‘test’
// Click the controller to view the LCD menu
#define LCD_LANGUAGE en

// LCD Charset ********************************************
// HD44780 Character Set
// This option applies only to character-based displays.
// Character-based displays (based on the Hitachi HD44780)
// provide an ASCII character set plus one of the following language extensions:
// JAPANESE … the most common
// WESTERN …. with more accented characters
// CYRILLIC … for the Russian language
// The LCD will display Japanese, Western, or Cyrillic text
#define DISPLAY_CHARSET_HD44780 JAPANESE

// SD Card ********************************************
// LCD_INFO_SCREEN_STYLE
// 0 for classic; 1 for Průša info screen style.
//#define LCD_INFO_SCREEN_STYLE 0

// Enable to use SD printing, whether as part of an LCD controller or as a standalone SDCard slot.
// The SDSUPPORT option must be enabled or SD printing will not be supported.
// It is no longer enabled automatically for LCD controllers with built-in SDCard slot.
//#define SDSUPPORT

// SPI Speed  ********************************************
// Uncomment ONE of these options to use a slower SPI transfer speed.
// This is usually required if you’re getting volume init errors.
//#define SPI_SPEED SPI_HALF_SPEED
//#define SPI_SPEED SPI_QUARTER_SPEED
//#define SPI_SPEED SPI_EIGHTH_SPEED

// Enable CRC
//#define SD_CHECK_AND_RETRY
// Use CRC checks and retries on the SD communication.

// LCD Menu Items
// Disable all menus and only display the Status Screen with NO_LCD_MENUS,
// or just remove some extraneous menu items to recover space with SLIM_LCD_MENUS.
//#define NO_LCD_MENUS
//#define SLIM_LCD_MENUS

// Encoder *************************************************
// Encoder Knob

// Encoder Resolution
// This option overrides the default number of encoder pulses needed to produce one step.
// Should be increased for high-resolution encoders.
//#define ENCODER_PULSES_PER_STEP 1

// Use this option to override the number of step signals required to move between next/prev menu items.
//#define ENCODER_STEPS_PER_MENU_ITEM 5

// Encoder Direction
// Test your encoder’s behavior first with both of the following options disabled.

// Reversed Value Edit and Menu Nav? Enable REVERSE_ENCODER_DIRECTION.
// Reversed Menu Navigation only? Enable REVERSE_MENU_DIRECTION.
// Reversed Value Editing only? Enable BOTH options.
//#define REVERSE_ENCODER_DIRECTION // This option reverses the encoder direction everywhere. Set if CLOCKWISE causes values to DECREASE.
//#define REVERSE_MENU_DIRECTION    // This option reverses the encoder direction for navigating LCD menus. If CLOCKWISE normally moves DOWN this makes it go UP. If CLOCKWISE normally moves UP this makes it go DOWN.
//#define REVERSE_SELECT_DIRECTION  // This option reverses the encoder direction for Select Screen If CLOCKWISE normally moves LEFT this makes it go RIGHT. If CLOCKWISE normally moves RIGHT this makes it go LEFT.

//#define INDIVIDUAL_AXIS_HOMING_MENU // Add individual axis homing items (Home X, Home Y, and Home Z) to the LCD menu.

// Speaker *************************************************
// By default Marlin assumes you have a buzzer with a fixed frequency.
// If you have a speaker that can produce tones, enable it here.
#define SPEAKER

// The duration and frequency for the UI feedback sound.
// Set these to 0 to disable audio feedback in the LCD menus.
// Test audio output with the G-code M300 S<frequency Hz> P<duration ms>
#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 100
#define LCD_FEEDBACK_FREQUENCY_HZ 1000


// LCD Controller *************************************************
// LCD Controllers

// Marlin includes support for several controllers. The two most popular controllers supported by Marlin are:

// REPRAP_DISCOUNT_SMART_CONTROLLER A 20 x 4 character-based LCD controller with click-wheel.
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER A monochrome 128 x 64 pixel-based LCD controller with click-wheel.
// Able to display simple bitmap graphics and up to 5 lines of text.
// Most other LCD controllers are variants of these. Enable just one of the following options for your specific controller:

// Character LCDs           Option             |Description
//                          ———————————————————|——————————–
//                          ULTIMAKERCONTROLLER|The original Ultimaker Controller.
//                          ULTIPANEL          |ULTIPANEL as seen on Thingiverse.
//                          PANEL_ONE          |PanelOne from T3P3 (via RAMPS 1.4 AUX2/AUX3).

// A variant of ULTIMAKERCONTROLLER.
// REPRAP_DISCOUNT_SMART_CONTROLLER            |RepRapDiscount Smart Controller.
// Usually sold with a white PCB. G3D_PANEL    |Gadgets3D G3D LCD/SD Controller. Usually sold with a blue PCB.
// RIGIDBOT_PANEL                              |RigidBot Panel V1.0. ANET_KEYPAD_LCD|Anet Keypad LCD for the Anet A3

// Graphical LCDs                        Option|Description
//                                  ———————————|———————————
//                                  CARTESIO_UI|Cartesio UI.
//                                    MAKRPANEL|MaKr3d Makr-Panel with graphic controller and SD support.
//                    REPRAPWORLD_GRAPHICAL_LCD|ReprapWorld Graphical LCD.
//                                        VIKI2|Panucatt Devices Viki 2.0.
//                                     miniVIKI|mini Viki with Graphic LCD.
//                  ELB_FULL_GRAPHIC_CONTROLLER|Adafruit ST7565 Full Graphic Controller.
//REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER|RepRapDiscount Full Graphic Smart Controller.
//                                    MINIPANEL|MakerLab Mini Panel with graphic controller and SD support.
//                      BQ_LCD_SMART_CONTROLLER|BQ LCD Smart Controller shipped with the BQ Hephestos 2 and Witbox 2.
//                       ANET_FULL_GRAPHICS_LCD|Anet Full Graphics LCD for the Anet A3

// Keypads    Option|Description
//REPRAPWORLD_KEYPAD|RepRapWorld Keypad v1.1 Use REPRAPWORLD_KEYPAD_MOVE_STEP
// to set how much the robot should move on each keypress (e.g., 10mm per click).

// I2C Character LCDs
// These controllers all require the LiquidCrystal_I2C library.

// Option	Description
// RA_CONTROL_PANEL	Elefu RA Board Control Panel
// LCD_I2C_SAINSMART_YWROBOT	Sainsmart YWRobot LCM1602 LCD Display.
// LCM1602	Generic LCM1602 LCD adapter
// LCD_I2C_PANELOLU2	PANELOLU2 LCD with status LEDs, separate encoder and click inputs.->
// The click input can either be directly connected to a pin (if BTN_ENC is defined) or ->
// read through I2C (with BTN_ENC undefined). Requires LiquidTWI2 library v1.2.3 or later.
// LCD_I2C_VIKI	Panucatt VIKI LCD with status LEDs, integrated click & L/R/U/D buttons, separate encoder inputs.
// SAV_3DLCD	Shift register panels. 2 wire Non-latching LCD SR. See LCD configuration.
// I2C Graphical LCDs
// These controllers all require the LiquidCrystal_I2C library.

// Option	Description
// U8GLIB_SSD1306	SSD1306 OLED full graphics generic display.
// SAV_3DGLCD	SAV OLED LCD module support using either SSD1306 or SH1106 based LCD modules.
// OLED_PANEL_TINYBOY2	TinyBoy2 128x64 OLED / Encoder Panel

// Fan PWM *************************************************
// Increase the FAN PWM frequency. Removes the PWM noise but increases heating in the FET/Arduino.
//#define FAST_PWM_FAN

// Use software PWM to drive the fan, as with the heaters.
// This uses a very low frequency which is not as annoying as with the hardware PWM.
// On the other hand, if this frequency is too low, you should also increment SOFT_PWM_SCALE.
//#define FAN_SOFT_PWM

// Incrementing this by 1 will double the software PWM frequency,
// affecting heaters (and the fan if FAN_SOFT_PWM is enabled).
// However, control resolution will be halved for each increment; at zero value, there are 128 effective control positions.
// #define SOFT_PWM_SCALE 0

//#define SOFT_PWM_DITHER
// If SOFT_PWM_SCALE is set to a value higher than 0,
// dithering can be used to mitigate the associated resolution loss.
// If enabled, some of the PWM cycles are stretched so on average the desired duty cycle is attained.

// Extra Features
// FAST_PWM_FAN increases the FAN PWM frequency. The frequency and scaling can be adjusted in Configuration_adv.h.
//#define FAST_PWM_FAN

// Use software PWM to drive the fan. This uses a very low frequency which is not as annoying as with the hardware PWM.
// Increase SOFT_PWM_SCALE if the frequency is too low.
// If experiencing resolution loss when SOFT_PWM_SCALE is set to a value greater than 0,
// SOFT_PWM_DITHER can be used to mitigate it. If enabled.
//#define FAN_SOFT_PWM
  #define SOFT_PWM_SCALE 0
  //#define SOFT_PWM_DITHER

// Photo Pin *************************************************
//#define PHOTOGRAPH_PIN     23 // M240 triggers a camera by emulating a Canon RC-1 Remote Data as described on this site.

// SkeinForge Arc Fix *************************************************
//#define SF_ARC_FIX Files sliced with SkeinForge contain the wrong arc G-codes when using “Arc Point” as fillet procedure. This option works around that bug, but otherwise should be left off.

// SkeinForge ARC G-code correction
//#define SF_ARC_FIX // Correct the wrong arc g-codes sent by SkeinForge when using Arc Point as fillet procedure

// Paste Extruder Support for the BariCUDA Paste Extruder.
//#define BARICUDA // Marlin includes support for the Baricuda Extruder for 3D Printing Sugar and Chocolate also hosted on GitHub. The feature adds the codes M126, M127, M128, and M129 for controlling the pump and valve of the Baricuda.

// LED Lights *************************************************

// Temperature Status LEDs 
//#define TEMP_STAT_LEDS 
// Temperature status LEDs that display the hotend and bed temperature.
// If all hotend and bed temperature set-point are < 54C then the BLUE led is on.
// Otherwise the RED led is on. There is 1C hysteresis.
// Adds a simple temperature status indicators using LEDs.

// RGB Color LEDs
// Marlin currently supplies two options for RGB-addressable color indicators.
// In both cases the color is set using M150 Rr Ug Bb to specify RGB components from 0 to 255.

//define BlinkM/CyzRgb Support
//#define BLINKM
// The BLINKM board supplies the backlighting for some LCD controllers. Its color is set using I2C messages.

//define PCA9632 PWM LED driver Support
//#define PCA9632
// The Philips PCA9632 is a common PWM LED driver, controlled (like BlinkM) using I2C.

// Support for PCA9533 PWM LED driver
//#define PCA9533
//#define RGB_LED
//#define RGBW_LED
  #if defined(RGB_LED) || defined(RGBW_LED)
    #define RGB_LED_R_PIN 34
    #define RGB_LED_G_PIN 43
    #define RGB_LED_B_PIN 35
    #define RGB_LED_W_PIN -1
#endif

// Enable support for an RGB(W) LED connected to 5 V digital pins, or an RGB(W) Strip connected to MOSFETs controlled by digital pins.
// An inexpensive RGB LED can be used simply by assigning digital pins for each component.
// If the pins are able to do hardware PWM then a wide range of colors will be available.
// With simple digital pins only 7 colors are possible.

// Adds the M150 command to set the LED (or LED strip) color.
// If pins are PWM capable (e.g., 4, 5, 6, 11) then a range of luminance values can be set from 0 to 255.

// LED Strips require a MOFSET Chip between PWM lines and LEDs,
// as the Arduino cannot handle the current the LEDs will require.
// Failure to follow this precaution can destroy your Arduino!

// Adafruit NeoPixel LED Driver
//#define NEOPIXEL_LED
  #if ENABLED(NEOPIXEL_LED)
    #define NEOPIXEL_TYPE   NEO_GRBW // NEO_GRBW / NEO_GRB - four/three channel driver type (defined in Adafruit_NeoPixel.h)
    #define NEOPIXEL_PIN     4       // LED driving pin
    //#define NEOPIXEL2_TYPE NEOPIXEL_TYPE
    //#define NEOPIXEL2_PIN    5
    #define NEOPIXEL_PIXELS 30       // Number of LEDs in the strip, larger of 2 strips if 2 NeoPixel strips are used
    #define NEOPIXEL_IS_SEQUENTIAL   // Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
    #define NEOPIXEL_BRIGHTNESS 127  // Initial brightness (0-255)
    //#define NEOPIXEL_STARTUP_TEST  // Cycle through colors at startup
    //#define NEOPIXEL_BKGD_LED_INDEX  0               // Index of the LED to use
    //#define NEOPIXEL_BKGD_COLOR { 255, 255, 255, 0 } // R, G, B, W
  #endif

// NEOPIXELS
// This option causes the printer to give status feedback on the installed color LED, BLINKM, or PCA9632:
// Gradually change from blue to violet as the heated bed gets to target temp.
// Gradually change from violet to red as the hotend gets to temperature.
// Change to white to illuminate work surface.
// Change to green once print has finished.
// Turn off after the print has finished and the user has pushed a button.
// Printer Event LEDs
  #if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
    #define PRINTER_EVENT_LEDS
#endif

// Servos *************************************************

// Number of Servos Servo index starts with 0 for M280 command
// The total number of servos to enable for use.
// One common application for a servo is a Z bed probe consisting of an endstop switch mounted on a rotating arm.
// To use one of the servo connectors for this type of probe, set Z_ENDSTOP_SERVO_NR in the probe options above.
//#define NUM_SERVOS 3

// Servo Deactivation
// Delay (in microseconds) before the next move will start,
// to give the servo time to reach its target angle.
// 300ms is a good value but you can try less delay.
// Specify a large enough delay so the servo has enough time to complete a full motion before deactivation.
#define SERVO_DELAY 300

// With this option servos are powered only during movement,
// then turned off to prevent jitter.
// We recommend enabling this option to keep electrical noise from active servos from interfering with other components.
// The high amperage generated by extruder motor wiring during movement can also induce movement in active servos.
// Leave this option enabled to avoid all such servo-related troubles.
//#define DEACTIVATE_SERVOS_AFTER_MOVE