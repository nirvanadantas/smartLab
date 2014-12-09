require 'socket'

hostname = '10.18.2.42'
port = 2330

s = TCPSocket.new(hostname, port)

le = true
while le
     s.puts 'a'
     sleep(0.2)
     s.puts 'b
     sleep(0.2)
end
