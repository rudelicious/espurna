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

#define NTP_SERVER                  "nl.pool.ntp.org"  // Default NTP server
#define NTP_TIMEZONE                TZ_Europe_Amsterdam      // POSIX TZ variable. Default to UTC from TZ.h (which is PSTR("UTC0"))

#define SENSOR_ENERGY_UNITS         ENERGY_KWH          // Energy units (ENERGY_JOULES | ENERGY_KWH)
#define SENSOR_POWER_UNITS          POWER_KILOWATTS     // Power units (POWER_WATTS | POWER_KILOWATTS)

#define MDNS_SERVER_SUPPORT         1           // Publish services using mDNS by default (1.48Kb)
// #define OTA_PORT                    8266        
// #define OTA_MQTT_SUPPORT            0           // Listen for HTTP(s) URLs at '<root topic>/ota'. Depends on OTA_CLIENT

//_SSL
#ifndef SECURE_CLIENT
#define SECURE_CLIENT                SECURE_CLIENT_BEARSSL     
// What variant of WiFiClient to use
// SECURE_CLIENT_NONE    - No secure client support (default)
// SECURE_CLIENT_AXTLS   - axTLS client secure support (All Core versions, ONLY TLS 1.1)
// SECURE_CLIENT_BEARSSL - BearSSL client secure support (starting with 2.5.0, TLS 1.2)
// axTLS marked for derecation since Arduino Core 2.4.2 and **will** be removed in the future
#endif

// Security check that is performed when the connection is established:
// SECURE_CLIENT_CHECK_CA           - Use Trust Anchor / Root Certificate
//                                    Supported only by the SECURE_CLIENT_BEARSSL
//                                    (See respective ..._SECURE_CLIENT_INCLUDE_CA options per-module)
// SECURE_CLIENT_CHECK_FINGERPRINT  - Check certificate fingerprint
// SECURE_CLIENT_CHECK_NONE         - Allow insecure connections

#ifndef SECURE_CLIENT_CHECK
#if SECURE_CLIENT == SECURE_CLIENT_BEARSSL
#define SECURE_CLIENT_CHECK                    SECURE_CLIENT_CHECK_CA
#else
#define SECURE_CLIENT_CHECK                    SECURE_CLIENT_CHECK_FINGERPRINT
#endif
#endif 
#ifndef SECURE_CLIENT_MFLN
#define SECURE_CLIENT_MFLN                     1024                      // The only possible values are: 512, 1024, 2048 and 4096
                                                                      // Set to 0 to disable (default)
#endif

#ifndef MQTT_SSL_ENABLED
#define MQTT_SSL_ENABLED            1               // By default MQTT over SSL will not be enabled
#endif
#ifndef MQTT_SSL_FINGERPRINT
#define MQTT_SSL_FINGERPRINT        ""              // SSL fingerprint of the server
#endif
#ifndef MQTT_SECURE_CLIENT_CHECK
#define MQTT_SECURE_CLIENT_CHECK    SECURE_CLIENT_CHECK // Use global verification setting by default
#endif
#ifndef MQTT_SECURE_CLIENT_MFLN
#define MQTT_SECURE_CLIENT_MFLN     SECURE_CLIENT_MFLN  // Use global MFLN setting by default
#endif
#ifndef MQTT_SECURE_CLIENT_INCLUDE_CA
#define MQTT_SECURE_CLIENT_INCLUDE_CA        1           // Use user-provided CA. Only PROGMEM PEM option is supported.
                                                         // When enabled, current implementation includes "static/mqtt_client_trusted_root_ca.h" with
                                                         // const char _mqtt_client_trusted_root_ca[] PROGMEM = "...PEM data...";
                                                         // By default, using LetsEncrypt X3 root in "static/letsencrypt_isrgroot_pem.h"
#endif

//_MQTT
#define MQTT_LIBRARY                MQTT_LIBRARY_PUBSUBCLIENT 
#define MQTT_SUPPORT                1           // MQTT support (22.38Kb async, 12.48Kb sync)
#define MQTT_ENABLED                1
#define MQTT_AUTOCONNECT            1           
#define MQTT_SERVER                 "mosquitto.local.lan" 
#define MQTT_USER                   ""              
#define MQTT_PASS                   ""              
#define MQTT_PORT                   8883 //1883            
#define MQTT_TOPIC                  "{hostname}"    
#define MQTT_USE_JSON               1       

//_
#define INFLUXDB_SUPPORT            0           // Disable InfluxDB support by default (4.38Kb)
#define ALEXA_SUPPORT               0
#define DOMOTICZ_SUPPORT            0
#define HOMEASSISTANT_SUPPORT       0
#define THINGSPEAK_SUPPORT          0               

