from math import floor

def convert10to2(num):
    if any(c in '/-;' for c in num) or num.count(',') + num.count('.') > 1:
        return "Número Inválido"

    num = num.replace(',', '.')

    if '.' in num:
        int_part, mantissa = map(float, num.split('.'))
        mantissa = float('0.' + str(int(mantissa)))
    else:
        int_part, mantissa = int(num), 0

    int_part = int(int_part)
    int_bin = []
    while int_part != 0:
        int_bin.append(int_part % 2)
        int_part //= 2
    
    int_bin.reverse()
    int_bin = ''.join(map(str, int_bin)) if int_bin else '0'

    int_bin = int_bin.rstrip('0')
    if not int_bin:  # Caso todo o binário seja zero
        int_bin = '0'

    man_bin = ''
    if mantissa:
        for _ in range(10):
            mantissa *= 2
            bit = floor(mantissa)
            man_bin += str(bit)
            mantissa -= bit
            if mantissa == 0:
                break

    return float(int_bin + '.' + man_bin) if man_bin else int(int_bin)


# @title **Código de teste para Atividade 1**
try:
  assert convert10to2("95") == 1011111
  assert convert10to2("123.234") == 1111011.0011101111
  assert convert10to2("37.52") == 100101.10000101
  assert convert10to2("0.625") == 0.101
  assert convert10to2("-21,12") == "Número Inválido"
  assert convert10to2("12/7") == "Número Inválido"
  assert convert10to2("23.43,2") == "Número Inválido"
  assert convert10to2("20;30") == "Número Inválido"

  print("Passou em todos os testes! :D")

except AssertionError:
  print(convert10to2("95"), 
        convert10to2("123.234"),
        convert10to2("37.52"),
        convert10to2("0.625"),
        convert10to2("-21,12"),
        convert10to2("12/7"),
        convert10to2("23.43,2"), 
        convert10to2("20;30"))
  print( "Falhou em um ou mais testes... :(")
  raise

def convert2to10(num):

    if any(c in '/-;' for c in num):
        return "Formatação numérica inválida."

    if any(c not in '01.,' for c in num) or num.count(',') + num.count('.') > 1:
        return "Número inserido não é binário."

    # Splitting integer and fractional parts
    if ',' in num or '.' in num:
        int_part, frac_part = num.replace(',', '.').split('.')
    else:
        int_part, frac_part = num, ''

    int_dec = 0
    for i, digit in enumerate(int_part):
        int_dec +=  int(int(digit) * int(2 ** int(len(int_part) - i - 1)))

    man_dec = 0
    if(frac_part):
        for i, digit in enumerate(frac_part):
            man_dec += float(float(digit) * float(2 ** -(i + 1)))


    return float(int_dec + man_dec) if man_dec else int_dec

# @title **Código de teste para Atividade 2**
try:
  assert convert2to10("100101.1000010100") == 37.51953125
  assert convert2to10("0.10011") == 0.59375
  assert convert2to10("10100011") == 163
  assert convert2to10("11011.111") == 27.875
  assert convert2to10("-101.111") == "Formatação numérica inválida."
  assert convert2to10("120.111") == "Número inserido não é binário."
  assert convert2to10("23.43,2") == "Número inserido não é binário."
  assert convert2to10("-101.1101,101") == "Formatação numérica inválida."

  print("Passou em todos os testes! :D")

except AssertionError:
  print( "Falhou em um ou mais testes... :(", convert2to10("100101.1000010100"), convert2to10("0.10011"), convert2to10("10100011"), convert2to10("11011.111"), convert2to10("-101.111"), convert2to10("120.111"), convert2to10("23.43,2"), convert2to10("-101.1101,101"))
