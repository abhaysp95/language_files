#!/usr/bin/env python

'''
a small tax deduction program
'''


def get_net_income(gross, state):
    '''
    calculates net income
    :param gross: Gross Income
    :state: State Name
    :returns: Net Income
    '''

    state_tax = {'LA': 4, 'DC': 3.5, 'Texas': 3.3, 'Hawaii': 4.5}

    net_income = gross - (gross * 0.10)  # 10% federal tax

    if state in state_tax.keys():
        net_income = net_income - (gross * state_tax[state] / 100)
        print(f"You net income is {net_income}")
        return net_income
    else:
        print('State not available in list')
        return None


if __name__ == "__main__":
    final = get_net_income(3000, 'Texas')
