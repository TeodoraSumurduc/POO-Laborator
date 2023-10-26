  This C++ program is intended to manage product orders and is designed with object-oriented principles. The program includes the following key components:

  Custom Exceptions: The code defines two custom exception classes, exceptie_pret (price exception) and exceptie_bucati (quantity exception), to handle errors related to product prices and quantities.

  Product Classes: Two product classes are implemented as derived classes: Carti (Books) and Alimente (Groceries). These classes inherit from the base class Produs (Product) and are used to represent different types of products, each with specific attributes.

  Inventar (Inventory): The Inventar class manages a collection of products. It provides methods for adding and displaying products. Products are stored as pointers to the base class, allowing for polymorphic behavior.

  Customer: The Customer class represents a customer and is implemented as a singleton. It allows for the creation of a single customer instance and stores their name.

  Comanda (Order): The Comanda class handles customer orders, including a list of products in an order. It is also implemented as a singleton. The class can add products to an order and display the order details.

  Template Function: The program contains a template function, afisareTotal, which displays order details for a specific product type while calculating the total price. It handles exceptions related to prices and quantities using custom exceptions.

  Overall, this code is a foundational structure for managing product orders within a retail or e-commerce context, with features for handling different types of products, individual customer orders, and error handling. It's worth noting that this is an initial framework, and the core functionality for handling and processing orders has yet to be implemented in the main function.


