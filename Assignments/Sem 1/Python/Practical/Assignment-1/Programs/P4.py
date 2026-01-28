# 4) Display trigonometric table of sin, cos and tan
import math
angles=[0,30,45,60,90]

print('Angle \t\tsin \t\t cos \t\t tan ')
for angle in angles :
 rad=math.radians(angle)
 sin=round( math.sin(rad),4)
 cos= round(math.cos(rad),4)
 if(angle==90):tan='undefiend'
 else :
  tan= round(math.tan(rad),4)
 print(f'{angle} \t\t {sin} \t\t {cos} \t\t {tan}')

 # output
#  Angle           sin              cos             tan 
# 0                0.0             1.0             0.0
# 30               0.5             0.866           0.5774
# 45               0.7071          0.7071          1.0
# 60               0.866           0.5             1.7321
# 90               1.0             0.0             undefiend