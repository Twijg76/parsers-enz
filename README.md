# parsers-enz: Een Shunting Yard Parser
Een Shunting Yard parser in C++ die een AST maakt. Ik had dit nodig voor
een project en kon geen voorbeeld of zelfs maar duidelijke omschrijving vond
van hoe dat precies werkt. Nu is er dus één, dit toont hoe ge van een string
naar een Abstract Syntax Tree geraakt.

De parser ondersteunt de operatoren \*+-/^ en haakjes maar geen unaire operaties.

Deze code valt onder de LGPL 3+. De volledige tekst vindt ge in het bestand
LICENCE. Ik vat de voor mij belangrijkste punten even samen, enkel de echte
tekst telt natuurlijk.

1. Vermeld waar ge de code vandaan hebt.
2. Ge moogt de code zoals hij is gebruiken in
   eender welk project zonder gevolgen.
3. Wanneer ge de code aanpast zijt ge verplicht die wijzigingen openbaar te
   maken onder een compatible licentie. (verbeteringen liefst ook aan deze
   repository toevoegen)
   
   
# ENG: A SHunting Yard Parser
This repository contains a simple Shunting Yard Parser from infix notation to an
AST or Abstract Syntax Tree. This code is under the LGPL so it's easy to use in
your project as long as you share your improvements to this code. The parser
supports the operators \*+-/^ and () but not unuary operators (yet).

