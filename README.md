Implementar, em RPC ou RMI um servidor de token. O servidor controla o acesso a um recurso pelos clientes entregando o direito de uso de um token. O cliente, após usar o recurso, informa o servidor que o token está disponível. O servidor, ao receber um pedido do uso do token, retorna true ou false. O retorno true indica que o cliente pode usar o recurso. O retorno false indica que o cliente não pode usar o recurso e uma nova tentativa deve ser feita posteriormente. A execução do experimento deve contemplar, pelo menos 10 clientes compartilhando o mesmo servidor, todos os clientes executando laços de 10 iterações solicitando o uso do recurso. Entre cada solicitação, o cliente deve "adormecer" alguns instantes, usando, por exemplo, a chamada de sistema sleep(tempo)



Deve ser submetido um arquivo zip ou gz (não mandem RAR) do diretório contendo os seguintes arquivos:

Fontes
Makefile para gerar o executável
Printscreen da tela com a compilação do programa, seu lançamento e resultado da execução.
