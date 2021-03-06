// ------------------------------------------------------------------------------
// Example file for custom.h 
// Either copy and paste this file then rename removing the .example or create your
// own file: 'custom.h'
// This file allows users to create their own configurations.
// See 'code/espurna/config/general.h' for default settings.
//
// See: https://github.com/xoseperez/espurna/wiki/Software-features#enabling-features
// and 'code/platformio_override.ini.example' for more details.
// ------------------------------------------------------------------------------

//
//@_ Configure custom settings (see: "general.h")

// #define WEB_USERNAME                "admin"     
// #define ADMIN_PASS                  "fibonacci"     // Default password (WEB, OTA, WIFI SoftAP)

#define NTP_SERVER                  "pool.ntp.org"  // Default NTP server
#define NTP_TIMEZONE                TZ_Europe_Amsterdam      // POSIX TZ variable. Default to UTC from TZ.h (which is PSTR("UTC0"))

#define SENSOR_ENERGY_UNITS         ENERGY_KWH          // Energy units (ENERGY_JOULES | ENERGY_KWH)
#define SENSOR_POWER_UNITS          POWER_KILOWATTS     // Power units (POWER_WATTS | POWER_KILOWATTS)

#define MDNS_SERVER_SUPPORT         0//1           // Publish services using mDNS by default (1.48Kb)

#define MQTT_SUPPORT                0           // MQTT support (22.38Kb async, 12.48Kb sync)
#define INFLUXDB_SUPPORT            0           // Disable InfluxDB support by default (4.38Kb)
#define ALEXA_SUPPORT               0
#define DOMOTICZ_SUPPORT            0
#define HOMEASSISTANT_SUPPORT       0
#define THINGSPEAK_SUPPORT          0               

#define SCHEDULER_SUPPORT           0           // Enable scheduler (2.45Kb)
#define TELNET_SUPPORT              0           // Enable telnet support by default (3.34Kb)