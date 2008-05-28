from era_comm import *
from time import sleep

p = ArmConfigPublisher()

def read_data( filename ):
  f = open( filename, 'r' )
  result = []
  for line in f:
    values = line.rsplit()
    conf = []
    for v in values:
      conf.append( float( v ) )
    result.append( conf )
  f.close()
  return result

configs   = read_data( "configs.dat"  )


while True:
  c = configs.pop( 0 )
  time = configs[0][5]
  p.shoulder_yaw   = c[0]
  p.shoulder_roll  = c[1]
  p.shoulder_pitch = c[2]
  p.ellbow_pitch   = c[3]
  p.tool_roll      = c[4]
  configs.append( c )
  print p.shoulder_yaw
  p.send()
  sleep( time )

