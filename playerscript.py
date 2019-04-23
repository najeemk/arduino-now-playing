from dbus.mainloop.glib import DBusGMainLoop
from mpris2 import get_players_uri, Player
import gi.repository.GLib
import serial
import time
import sys

DBusGMainLoop(set_as_default=True)
uri = next(get_players_uri())

song_name = "Example"

def another_handler(self, *args, **kw):
    if (song_name != player.Metadata['xesam:title']):
        update_song()

def update_song():
    global song_name
    metadata = player.Metadata
    song_name = metadata['xesam:title']
    artist_name = artist_name = (metadata['xesam:artist'][0])
    arduino.write((song_name + "*" + artist_name + "*").encode())

arduino = serial.Serial('/dev/ttyACM0', 9600) 
time.sleep(2)
player = Player(dbus_interface_info={'dbus_uri': uri})
player.PropertiesChanged = another_handler
mloop = gi.repository.GLib.MainLoop()
update_song()
mloop.run()
