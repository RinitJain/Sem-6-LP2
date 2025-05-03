#Inventory Management Chatbot for an e-commerce store

import re
from nltk.chat.util import Chat, reflections

#Create Store Inventory
inventory = {
    'laptop' : {'price':50000, 'stock':40},
    'headphone' : {'price':5000, 'stock':25},
    'phone' : {'price':40000, 'stock':50},
    'watch' : {'price':3000, 'stock':30}
}

#Chat patterns for static responses

patterns = [
    (r'(?i)^(hi|hello|hey)$',
     ['Hello! I am your AI powered chatbot, how can I help you?', 'Hey, I am your AI powered chatbot, what assitance do you need?']),

    (r'(.*) products?', 
     ['We currently have: ' + ', '.join(inventory.keys()) + '. Which product are you interested in?']),

    (r'(?i)(thank you|thanks)',
     ['You are most welcome! Let me know how I can help you further.']),

    (r'.*',
     ['Sorry I dont understand! Please let me know if you want to see our products list, or other product details.'])
]

#Purchase Handler
def purchase_handler(product, quantity):
    item = inventory.get(product)
    if item:
        if item['stock'] >= quantity:
            item['stock'] -= quantity
            total = item['price']*quantity
            return (f"Bot: Purchase successfully! {quantity} {product}(s) were bought for a price of Rs. {total}. Remaining stock: {item['stock']}.")
        else:
            return (f"Sorry, only {item['stock']} {product}(s) left in stock.")
    return (f"{product} is not available in our inventory.")

#Create chatbot
bot = Chat(patterns, reflections)

#Main Handler
def main():
    print('Welcome to the Inventory chatbot! How can I help you?')
    while True:
        user_input = input("You: ").strip()

        #Handle Price Queries
        price_match = re.search(r'(?i)price of (\w+)', user_input)
        if(price_match):
            product = price_match.group(1).lower()
            if product in inventory:
                print(f"Bot: The price of {product} is Rs. {inventory[product]['price']}.")
            else:
                print(f"Bot: Sorry, {product} is not in stock.")
            continue

        #Handle Stock Queries
        stock_match = re.search(r'(?i)stock of (\w+)', user_input)
        if(stock_match):
            product = stock_match.group(1)
            if product in inventory:
                print(f"Bot: {inventory[product]['stock']} pieces of {product} are available with us.")
            else:
                print(f"Bot: Sorry, {product} is not in stock.")
            continue

        #Handle Buy Queries
        if "buy" in user_input.lower():
            product = input("Bot: Which product do you want to buy?")
            try:
                quantity = int(input(f"Bot: How many {product}s would you like to purchase?"))
                print(purchase_handler(product.lower() , quantity))
            except ValueError:
                print("Bot: Please enter a valid quantity.")
            continue
            
        #Handle Exit Queries
        if re.search(r'(?i)\b(bye|exit)\b', user_input):
            print("Bot: I hope you liked out service! Visit soon!")
            break

        #For General Queries use Patterns
        response = bot.respond(user_input)
        if response:
            print("Bot: ", response)
        continue

if __name__ == "__main__":
    main()