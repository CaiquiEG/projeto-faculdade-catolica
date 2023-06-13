import openai

cadastros = list()
cod_p = {}

cadastros.append({'nome': 'Caiqui',
                  'idade': '18',
                  'usuario': 'caiqui',
                  'senha': '18006'})
produtos = list()
compras = list()

def consultarchatgpt(productName):
    openai.api_key = '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'

    # Set the model and prompt
    model_engine = "text-davinci-003"
    prompt = 'me diga resumidamente o que você acha do ' + productName + ' ?'
    # Set the maximum number of tokens to generate in the response
    max_tokens = 1024

    # Generate a response
    completion = openai.Completion.create(
        engine=model_engine,
        prompt=prompt,
        max_tokens=max_tokens,
        temperature=0.5,
        top_p=1,
        frequency_penalty=0,
        presence_penalty=0
    )

    # Print the response
    return completion.choices[0].text
def menu_cadatro():
    print('1- Realizar Cadastro\n2- Realizar Login\n3- Encerrar')


def menu_principal():
    print('1- Alterar dados\n2- Cadastrar itens'
          '\n3- Listar itens\n4- Alterar itens\n'
          '5-Excluir produto\n6- Buscar item\n7- Fazer Logout')


def excluir(produtos, indice):
    if indice >= 0 and indice < len(produtos):
        produtoremovido = produtos.pop(indice)
        print("Produto removido:", produtoremovido, 'com sucesso')
    else:
        print("Produto não encontrado")


i = 0
while True:
    menu_cadatro()
    resposta = int(input('Digite a opção desejada: '))
    if resposta == 1:
        nome = str(input('Digite o nome: '))
        idade = str(input('Digite a idade: '))
        usuario = str(input('Digite o usuario: '))
        senha = str(input('Digite a senha: '))

        userData = {
            'nome': nome,
            'idade': idade,
            'usuario': usuario,
            'senha': senha
        }
        userEXists = False

        for index in range(len(cadastros)):
            if cadastros[index]['usuario'] == userData['usuario']:
                print('SISTEMA-> Usuário já existente.')
                userEXists = True
                break
        if ~userEXists:
            cadastros.append(userData)
            print('SISTEMA-> Usuário cadastrado!')

    elif resposta == 2:
        if len(cadastros) == 0:
            print('SISTEMA-> Nenhum cadastro realizado!')
            continue

        login = str(input('Digite o usuario: '))
        senha = str(input('Digite a senha: '))
        usuario = str()

        for index, cadastro in enumerate(cadastros):
            if (cadastros[index]['usuario'] == login
                    and cadastros[index]['senha'] == senha):
                usuario = cadastros[index]['usuario']
                print('SISTEMA-> Login realizado!')
                while True:
                    menu_principal()

                    resposta = int(input('Digite a opção desejada: '))
                    if (resposta == 1):
                        print(f'Alterar Dados:\n'
                              f'1- Nome ({cadastros[index]["nome"]})\n'
                              f'2- Idade ({cadastros[index]["idade"]})\n'
                              f'3- Usuário ({cadastros[index]["usuario"]})\n'
                              f'4- Senha ({cadastros[index]["senha"]})\n'
                              f'[qualquer número]- Voltar')

                        option = int(input('Digite a opção desejada: '))
                        if option == 1:
                            cadastros[index]['nome'] = str(input('Digite o nome: '))
                            print('SISTEMA-> Nome atualizado.')
                        elif option == 2:
                            cadastros[index]['idade'] = str(input('Digite a idade: '))
                            print('SISTEMA-> Idade atualizada.')
                        elif option == 3:
                            cadastros[index]['usuario'] = str(input('Digite o Usuário: '))
                            print('SISTEMA-> Usuário atualizado.')
                        elif option == 4:
                            cadastros[index]['senha'] = str(input('Digite a senha: '))
                            print('SISTEMA-> Senha atualizada.')
                    elif resposta == 2:
                        print(f'Cadastrar itens:')
                        nome = str(input('Digite o nome: '))
                        valor = float(input('Digite o preço: '))
                        #desc = str(input('Digite o Descrição: '))
                        desc = consultarchatgpt(nome)

                        productEXists = False
                        for index in range(len(produtos)):
                            if (produtos[index]['nome'] == nome):
                                productEXists = True
                                print('SISTEMA-> Produto já existente.')
                                break
                        if not productEXists:
                            if len(produtos) == 0:
                                produtos.append({
                                    'nome': nome,
                                    'valor': valor,
                                    'descricao': desc,
                                    'codigo': 0
                                })
                            else:
                                produtos.append({
                                    'nome': nome,
                                    'valor': valor,
                                    'descricao': desc,
                                    'codigo': len(produtos)
                                })

                        print('SISTEMA-> Item cadastrado!')
                    elif resposta == 3:
                        print('Listar itens:')
                        if len(produtos) == 0:
                            print('SISTEMA-> Nenhum produto cadastrado!')
                        else:
                            for index in range(len(produtos)):
                                print(f'Nome: {produtos[index]["nome"]}\n'
                                      f'Preço: {produtos[index]["valor"]}\n'
                                      f'Descrição: {produtos[index]["descricao"]}\n'
                                      f'codigo do produto: {produtos[index]["codigo"]}\n'
                                      f'----------------------\n')


                    elif resposta == 4:
                        if len(produtos) == 0:
                            print('SISTEMA-> Nenhum produto cadastrado!')
                            continue
                        else:
                            print('Alterar itens:\n'
                                  '1- Nome\n'
                                  '2- Preço\n'
                                  '3- descrição\n'
                                  '[qualquer número]- Voltar')
                            resposta = int(input('Digite a opção desejada: '))
                            if resposta == 1:
                                nome = str(input('Digite o nome: '))
                                produto = str(input('Alterar para: '))
                                for index in range(len(produtos)):
                                    if produtos[index]['nome'] == nome:
                                        produtos[index]['nome'] = produto
                                        print('SISTEMA-> Nome atualizado.')
                                    else:
                                        print('SISTEMA-> Produto já existe')
                            elif resposta == 2:
                                valor = float(input('Digite o Valor: '))
                                produto = float(input('Alterar para: '))
                                for index in range(len(produtos)):
                                    if produtos[index]['valor'] == float(valor):
                                        produtos[index]['valor'] = produto
                                        print('SISTEMA-> Preço atualizado.')
                                    else:
                                        print('SISTEMA-> Preço não foi alterado')
                            elif resposta == 3:
                                desc = str(input('Digite a Descriç ão do produto: '))
                                produto = str(input('Alterar para: '))
                                for index in range(len(produtos)):
                                    if produtos[index]['descricao'] == desc:
                                        produtos[index] ['descricao'] = produto
                                        print('SISTEMA-> Descrição alterada')
                                    else:
                                        print('SISTEMA-> descrição ja existente')

                    elif resposta == 5:
                        p = int(input('SISTEMA-> Digite o codigo do produto que você quer excluir:'))
                        excluir(produtos, p)
                    elif resposta == 6:
                        if len(produtos) == 0:
                            print('SISTEMA-> Nenhum produto cadastrado!')
                            continue
                        print('1-Procurar por nome\n2-Para procurar por descrição')
                        busca = int(input('Digite a opção: '))
                        if busca == 1:
                            flag = True
                            while flag:
                                productFound = ''
                                nomeproduto = str(input('SISTEMA-> Digite o nome do produto: '))
                                for index in range(len(produtos)):
                                    if produtos[index]['nome'] == nomeproduto:
                                        print(f'Nome: {produtos[index]["nome"]}\n'
                                              f'Preço: {produtos[index]["valor"]}\n'
                                              f'Descrição: {produtos[index]["descricao"]}\n'
                                              f'codigo do produto: {produtos[index]["codigo"]}\n')
                                        productFound = produtos[index]

                                if productFound != '':
                                    print('1-Proceder com a comprar\n2- Voltar (mantendo o carrinho)')
                                    buyerOption = int(input('Digite a opção:'))
                                    if buyerOption == 1:
                                        quant = int(input('Digite a quantidade:'))
                                        print(f'Nome: {produtos[index]["nome"]}\n'
                                              f'Preço: {produtos[index]["valor"]}\n'
                                              f'Descrição: {produtos[index]["descricao"]}\n'
                                              f'Quantidade: ', quant)
                                        print('1- Finalizar Compra\n2- Continuar comprando \n3- Cancelar')
                                        cartOption = int(input('Digite a opção: '))
                                        compras.append({
                                            'nome': produtos[index]["nome"],
                                            'valor': produtos[index]["valor"],
                                            'Quantidade': quant
                                        })
                                        if cartOption == 1:
                                            for index in range(len(compras)):
                                                print(f'Nome: {compras[index]["nome"]}\n'
                                                      f'Preço: {compras[index]["valor"]}\n'
                                                      f'Quantidade: {compras[index]["Quantidade"]}')
                                                total = (compras[index]["valor"] * compras[index]["Quantidade"])
                                                print('Total da compra: ', total)
                                            compras = list()
                                            flag = False
                                        elif cartOption == 2:
                                            compras.append({
                                                'nome': produtos[index]["nome"],
                                                'valor': produtos[index]["valor"],
                                                'Quantidade': quant
                                            })
                                        elif cartOption == 3:
                                            flag = False
                                            compras = list()
                                            break
                                    elif buyerOption == 2:
                                        flag = False
                                        break
                                else:
                                    print('Compra cancelada')
                                    flag = False

                        elif busca == 2:
                            flag = True
                            while flag:
                                productFound = ''
                                descproduto = str(input('Digite a descrição do produto: '))
                                for index in range(len(produtos)):
                                    if produtos[index]['descricao'] == descproduto:
                                        print(f'Nome: {produtos[index]["nome"]}\n'
                                              f'Preço: {produtos[index]["valor"]}\n'
                                              f'Descrição: {produtos[index]["descricao"]}\n'
                                              f'codigo do produto: {produtos[index]["codigo"]}\n')
                                        productFound = produtos[index]

                                if productFound != '':
                                    print('1-Proceder com a comprar\n2- Voltar (mantendo o carrinho)')
                                    buyerOption = int(input('Digite a opção:'))
                                    if buyerOption == 1:
                                        quant = int(input('Digite a quantidade:'))
                                        print(f'Nome: {produtos[index]["nome"]}\n'
                                              f'Preço: {produtos[index]["valor"]}\n'
                                              f'Descrição: {produtos[index]["descricao"]}\n'
                                              f'Quantidade: ', quant)
                                        print('1- Finalizar Compra\n2- Continuar comprando \n3- Cancelar')
                                        cartOption = int(input('Digite a opção: '))
                                        compras.append({
                                            'nome': produtos[index]["nome"],
                                            'valor': produtos[index]["valor"],
                                            'Quantidade': quant
                                        })
                                        if cartOption == 1:
                                            for index in range(len(compras)):
                                                print(f'Nome: {compras[index]["nome"]}\n'
                                                      f'Preço: {compras[index]["valor"]}\n'
                                                      f'Quantidade: {compras[index]["Quantidade"]}')
                                                total = (compras[index]["valor"] * compras[index]["Quantidade"])
                                                print('Total da compra: ', total)
                                            compras = list()
                                            flag = False
                                        elif cartOption == 2:
                                            compras.append({
                                                'nome': produtos[index]["nome"],
                                                'valor': produtos[index]["valor"],
                                                'Quantidade': quant
                                            })
                                        elif cartOption == 3:
                                            flag = False
                                            compras = list()
                                            break
                                    elif buyerOption == 2:
                                        flag = False
                                        break
                                else:
                                    print('Compra cancelada')
                                    flag = False
                    elif resposta == 7:
                        break
                    else:
                        print('SISTEMA-> Opção inválida.')

                break

        if login != usuario:
            print('SISTEMA-> Credenciais incorretas!')

    elif resposta == 3:
        break

    else:
        print('SISTEMA-> Opção inválida.')
