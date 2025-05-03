# Inventory Management Chatbot

This is a simple inventory management chatbot built with Python and NLTK. It allows users to interact via a conversational interface to view product prices, check stock levels, and make purchases from a predefined inventory.

---

## Tech Stack

* Python
* NLTK (Natural Language Toolkit)
* Regular Expressions (re module)

---

## Inventory

The chatbot currently manages the following items:

* Laptop: ₹50,000
* Headphone: ₹5,000
* Phone: ₹40,000
* Watch: ₹3,000

---

## Example Usage

```text
Welcome to the Inventory chatbot! How can I help you?

You: hello
Bot: Hello! I am your AI powered chatbot, how can I help you?

You: what products do you have
Bot: We currently have: laptop, headphone, phone, watch. Which product are you interested in?

You: price of laptop
Bot: The price of laptop is Rs. 50000.

You: stock of watch
Bot: 30 pieces of watch are available with us.

You: buy
Bot: Which product do you want to buy?
You: phone
Bot: How many phones would you like to purchase?
You: 2
Bot: Purchase successfully! 2 phone(s) were bought for a price of Rs. 80000. Remaining stock: 48.

You: bye
Bot: I hope you liked our service! Visit soon!
```

---

## 💪 Customization

You can easily:

* Add more products to the inventory dictionary
* Add new conversation patterns to the patterns list
* Extend command recognition with new regular expressions

---

