import cantools
import can

# 1. Load your defined protocol
db = cantools.database.load_file('engine.dbc')

# 2. Encode data (Physical Values -> Raw CAN Frame)
data_dict = {'RPM': 3000, 'Temperature': 85, 'Status': 1}
can_frame = db.encode_message('EngineData', data_dict)

# 3. Send via vcan0
bus = can.interface.Bus(channel='vcan0', bustype='socketcan')
msg = can.Message(arbitration_id=0x100, data=can_frame, is_extended_id=False)
bus.send(msg)
print(f"Sent: {data_dict}")

# 4. Decode received data (Raw CAN Frame -> Physical Values)
# (Simulating a receive for demonstration)
decoded_data = db.decode_message('EngineData', can_frame)
print(f"Received: {decoded_data}")