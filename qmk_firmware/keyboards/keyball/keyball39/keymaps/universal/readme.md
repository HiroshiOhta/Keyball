# Keyball39 universal keymap

This single keymap is intended for both the Windows PC and the Mac. The physical roles from the supplied layer map are kept: `KC_LGUI` is the Windows key on Windows and Command on macOS; `KC_LALT` is Alt on Windows and Option on macOS. The same firmware image should be written to both Pro Micros.

QMK host OS detection is not enabled because these standard modifier roles do not need different keycodes. If OS-specific shortcut macros are added later, host detection can be added for those actions.

Layer 0-2 reproduce the supplied keymap sheet. Following the official Keyball layout, Layer 1 is the Auto Mouse target and Layer 3 is the manual scroll layer. Moving the trackball while Layer 3 is active scrolls instead of moving the pointer. Hold Tab to enter Layer 3; tapping Tab still sends Tab. The two unused right-thumb positions on Layer 1 send left and right mouse clicks. Auto Mouse is enabled after Keyball's EEPROM settings load so its saved disabled state cannot prevent automatic layer activation.

Build from the QMK 0.22.14 checkout after linking the Keyball keyboard folder:

```sh
make SKIP_GIT=yes keyball/keyball39:universal
```

This is a compile target only. Flashing either Pro Micro requires a separate user-approved step.

## Remap viewing

VIA is enabled so Remap can display this keymap using the Keyball39 layout definition. Treat `keymap.c` as the source of truth and use Remap for viewing or printing only; edits made in Remap are stored in EEPROM and are not recorded in Git.

VIA copies the compiled default keymap into EEPROM on first initialization. After changing `keymap.c`, clear EEPROM on both Pro Micros so the new compiled layout is loaded. Clearing EEPROM can also reset other saved Keyball settings.

RGB underglow is disabled to leave enough flash space for VIA on the ATmega32U4 Pro Micro.
