require 'socket'

ip = "10.18.2.42"
porta = 2330

begin
server = TCPSocket.open ip, porta

puts "Conectado ao servidor" + ip + ":" + porta
server.close
end
