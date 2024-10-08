# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Board selection
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.
SERIAL_DRIVER = vendor
#ALLOW_WARNINGS = yes

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
TAP_DANCE_ENABLE = yes		# Enable tap dance
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
