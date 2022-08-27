lst = ['Unnamed: 0', 'id', 'date', 'price', 'bedrooms', 'bathrooms', 
'sqft_living', 'sqft_lot', 'floors', 'waterfront', 'view', 'condition', 
'year_built', 'year_renovated', 'zipcode']

print(*lst, sep="\n")


lst = ["libor", "gold", "treasury_bond", "stock_options"]

print(enumerate(*lst, 100), sep="\n")


