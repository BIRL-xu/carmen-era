from era_comm import *

p = ArmConfigSubscriber()

while True:
  EraComm.instance().listen( 0.001 )
  print p.shoulder_yaw